#include "ft_printf.h"
/* ************************************************************************** */
/*   Test harness for ft_printf (NOT submitted, NOT graded)                   */
/*                                                                            */
/*   Build:  make && cc -Wall -Wextra main.c -L. -lftprintf -o test           */
/*   Run:    ./test                                                           */
/*   Leaks:  valgrind --leak-check=full ./test                                */
/*   ASan:   cc -g -fsanitize=address main.c -L. -lftprintf -o test           */
/*                                                                            */
/*   Do NOT compile with -Werror: some formats below are deliberately odd.    */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include "ft_printf.h"

#define TMP_FILE "/tmp/ft_printf_test.txt"
#define BUF_SIZE 65536

static char	g_exp[BUF_SIZE];
static char	g_got[BUF_SIZE];
static int	g_saved;
static int	g_pass;
static int	g_fail;

static void	begin_capture(void)
{
	int	fd;

	fflush(stdout);
	g_saved = dup(1);
	fd = open(TMP_FILE, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	dup2(fd, 1);
	close(fd);
}

static int	end_capture(char *out)
{
	int		fd;
	ssize_t	n;

	fflush(stdout);
	dup2(g_saved, 1);
	close(g_saved);
	fd = open(TMP_FILE, O_RDONLY);
	n = read(fd, out, BUF_SIZE - 1);
	close(fd);
	if (n < 0)
		n = 0;
	out[n] = '\0';
	return ((int)n);
}

static void	show(const char *label, const char *s, int len)
{
	int	i;

	printf("    %s: [", label);
	i = 0;
	while (i < len && i < 120)
	{
		if (s[i] == '\0')
			printf("\\0");
		else if (s[i] == '\n')
			printf("\\n");
		else
			putchar(s[i]);
		i++;
	}
	printf("%s]\n", len > 120 ? "..." : "");
}

static void	check(const char *name, int r1, int r2, int l1, int l2)
{
	int	ok;

	ok = (r1 == r2 && l1 == l2 && memcmp(g_exp, g_got, l1) == 0);
	if (ok)
	{
		g_pass++;
		printf("[ OK ] %s\n", name);
		return ;
	}
	g_fail++;
	printf("[FAIL] %s\n", name);
	show("expected", g_exp, l1);
	show("got     ", g_got, l2);
	printf("    return  expected %d, got %d\n", r1, r2);
}

/* Runs printf and ft_printf with the same arguments and compares them */
#define TEST(...) \
	do { \
		int	r1; \
		int	r2; \
		int	l1; \
		int	l2; \
		begin_capture(); \
		r1 = printf(__VA_ARGS__); \
		l1 = end_capture(g_exp); \
		begin_capture(); \
		r2 = ft_printf(__VA_ARGS__); \
		l2 = end_capture(g_got); \
		check(#__VA_ARGS__, r1, r2, l1, l2); \
	} while (0)

/* For undefined behaviour: only checks the return value you chose */
#define EXPECT_RET(expected, ...) \
	do { \
		int	r; \
		begin_capture(); \
		r = ft_printf(__VA_ARGS__); \
		end_capture(g_got); \
		if (r == (expected)) \
		{ \
			g_pass++; \
			printf("[ OK ] %s -> %d\n", #__VA_ARGS__, r); \
		} \
		else \
		{ \
			g_fail++; \
			printf("[FAIL] %s -> %d (wanted %d)\n", #__VA_ARGS__, r, \
				(expected)); \
		} \
	} while (0)

static void	section(const char *title)
{
	printf("\n=== %s ===\n", title);
}

int	main(void)
{
	char	*null_str = NULL;
	int		var = 42;
	char	long_str[5000];

	section("plain text and walker");
	TEST("");
	TEST("hello");
	TEST("hello world\n");
	TEST("   ");
	TEST("a\tb\n");

	section("%%");
	TEST("%%");
	TEST("100%%");
	TEST("%%%%");
	TEST("%%%%%%");
	TEST("a%%b%%c");
	TEST("%% %d", 5);
	TEST("%d %% %d", 1, 2);

	section("%c");
	TEST("%c", 'A');
	TEST("%c", '0');
	TEST("%c", ' ');
	TEST("%c", 0);
	TEST("%c%c%c", 'a', 'b', 'c');
	TEST("[%c]", 0);
	TEST("%c", 255);
	TEST("%c", 'A' + 256);

	section("%s");
	TEST("%s", "hello");
	TEST("%s", "");
	TEST("%s", null_str);
	TEST("[%s]", "");
	TEST("%s%s%s", "a", "", "b");
	TEST("%s %s", "hello", "world");
	TEST("%s", "with\nnewline");
	TEST("%s and %s", "x", null_str);

	section("%d / %i");
	TEST("%d", 0);
	TEST("%d", 1);
	TEST("%d", -1);
	TEST("%d", 9);
	TEST("%d", 10);
	TEST("%d", -10);
	TEST("%d", 42);
	TEST("%d", -42);
	TEST("%d", 100);
	TEST("%d", 123456789);
	TEST("%d", INT_MAX);
	TEST("%d", INT_MIN);
	TEST("%d", INT_MIN + 1);
	TEST("%i", 0);
	TEST("%i", -123);
	TEST("%i", INT_MAX);
	TEST("%i", INT_MIN);
	TEST("%d%d", 1, 2);
	TEST("%d %i", -5, -6);

	section("%u");
	TEST("%u", 0);
	TEST("%u", 1);
	TEST("%u", 42);
	TEST("%u", 4294967295u);
	TEST("%u", UINT_MAX);
	TEST("%u", -1);
	TEST("%u", INT_MIN);
	TEST("%u", INT_MAX);
	TEST("%u", 3000000000u);

	section("%x");
	TEST("%x", 0);
	TEST("%x", 1);
	TEST("%x", 9);
	TEST("%x", 10);
	TEST("%x", 15);
	TEST("%x", 16);
	TEST("%x", 255);
	TEST("%x", 256);
	TEST("%x", 3735928559u);
	TEST("%x", -1);
	TEST("%x", INT_MIN);
	TEST("%x", INT_MAX);
	TEST("%x", UINT_MAX);

	section("%X");
	TEST("%X", 0);
	TEST("%X", 10);
	TEST("%X", 255);
	TEST("%X", 3735928559u);
	TEST("%X", -1);
	TEST("%X", INT_MIN);
	TEST("%X", UINT_MAX);
	TEST("%x %X", 255, 255);

	section("%p");
	TEST("%p", NULL);
	TEST("%p", &var);
	TEST("%p", (void *)1);
	TEST("%p", (void *)255);
	TEST("%p", (void *)-1);
	TEST("%p", (void *)LONG_MAX);
	TEST("%p", (void *)LONG_MIN);
	TEST("%p", (void *)ULONG_MAX);
	TEST("%p", (void *)0x7fffffffffffUL);
	TEST("%p %p", &var, NULL);
	TEST("%p", "a string literal");

	section("mixed formats");
	TEST("%c%s%d%i%u%x%X%p%%", 'a', "b", 1, 2, 3, 255, 255, &var);
	TEST("%d %s %x %%", 42, "answer", 255);
	TEST("Hello %s, you are %d years old (%c)\n", "Bob", 30, 'x');
	TEST("%s%s", "abc", "def");
	TEST("%d%d%d%d%d", 1, 2, 3, 4, 5);
	TEST("%x%X%x%X", 10, 10, 11, 11);
	TEST("%c%%%c", 'a', 'b');
	TEST("|%s|%s|%s|", "", "", "");
	TEST("%u %d %x", -1, -1, -1);
	TEST("%s %p %d", null_str, NULL, 0);

	section("long output");
	memset(long_str, 'z', sizeof(long_str) - 1);
	long_str[sizeof(long_str) - 1] = '\0';
	TEST("%s", long_str);
	TEST("start %s end", long_str);

	section("return value is the byte count");
	TEST("%d", 12345);
	TEST("%c", 'x');
	TEST("abc%sdef", "123");
	TEST("%s", "");
	TEST("%c", 0);

	section("undefined behaviour (YOUR policy: policy A -> -1)");
	EXPECT_RET(-1, "%");
	EXPECT_RET(-1, "abc%");
	EXPECT_RET(-1, "%d%", 5);
	EXPECT_RET(-1, "%k");

	printf("\n==============================\n");
	printf("passed: %d   failed: %d\n", g_pass, g_fail);
	return (g_fail != 0);
}