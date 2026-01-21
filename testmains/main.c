#include "./libasm.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <errno.h>

static void    ft_strlen_test_one_string(char *str){
    size_t ft_strlen_ret = ft_strlen(str);
    int errno_ret = errno;
    size_t strlen_ret = strlen(str); // null pointer case for standard strlen
    int errno_ret_std = errno;
    printf("str: %s,\n ft_strlen returned: %lu\n    strlen returned: %lu\t%s\terrno: %d\terrno_std: %d\t%s\n", str, ft_strlen_ret, strlen_ret,
        (ft_strlen_ret != strlen_ret) ? "❌" : "✅",
        errno_ret, errno_ret_std,
        (errno_ret != errno_ret_std) ? "❌" : "✅"
    );
}

static void    ft_strlen_test(){
    ft_strlen_test_one_string("Hello World!\n");
    ft_strlen_test_one_string("1");
    ft_strlen_test_one_string("12");
    ft_strlen_test_one_string("123");
    // ft_strlen_test_one_string(NULL); // this will segfault in standard strlen
    ft_strlen_test_one_string("");
    ft_strlen_test_one_string("ervhgw rgss dghbsidsf gdshg fdsgbgdhlkbfdljgdsfklvndlkfgjns;ldfkhs;dfjkl'sdlfkgjnk;ldsfjhgblidslkgnvlksrjfdgn"
        " gfl ghkg fhgfvbsgbskg fssfgsfvhrgshvfhkfjhhjvfjhkfdshbdvfsfhbhffhdsjhfdfdsjfdsfhfdfhdjfdsjhgjfdgfhgfdsjg"
        "hfdshsfdhghgjdsfsdhgjfsjfdsjhgfsfhkfgshkjfshjshfgshkfsfskhfhkfsjkfhjsdf");
    ft_strlen_test_one_string("\n");   
}


static void    ft_strcmp_test_two_strings(char *str1, char *str2){
    int ft_strcmp_ret = ft_strcmp(str1, str2);
    int strcmp_ret = strcmp(str1, str2); // null pointer case for standard strcmp
    printf("str1: '%s',\tstr2: '%s',\n ft_strcmp returned: %d\n    strcmp returned: %d\t%s\n", str1, str2, ft_strcmp_ret, strcmp_ret,
        (ft_strcmp_ret != strcmp_ret) ? "❌" : "✅");
}
static void    ft_strcmp_test(){
    // causes segfaults in standard strcmp:
    // ft_strcmp_test_two_strings(NULL, NULL);
    // ft_strcmp_test_two_strings(NULL, "hello!");
    // ft_strcmp_test_two_strings("hello", NULL);

    ft_strcmp_test_two_strings("hello", "hello");
    ft_strcmp_test_two_strings("hello", "hello!");
    ft_strcmp_test_two_strings("aboba", "abobus");
    ft_strcmp_test_two_strings("", "");
    ft_strcmp_test_two_strings("1", "");
    ft_strcmp_test_two_strings("", "1");
    ft_strcmp_test_two_strings("123", "1");
}

static void ft_strcpy_test_one_string(char *str){
    char buf[5000];
    char *ft_ret, *ret;
    int errno_ret = 0, errno_ret_std = 0;
    {
        memset(buf, 0, 5000);
        printf("strSrc: '%s',\tstrDst: '%s',\t", str, buf);
        ft_ret = ft_strcpy(buf, str);
        errno_ret = errno;
        printf("strDst after: '%s',\tft_strcpy returned: '%s'\n", buf, ft_ret);
    }
    {
        memset(buf, 0, 5000);
        printf("strSrc: '%s',\tstrDst: '%s',\t", str, buf);
        ret = strcpy(buf, str);
        errno_ret_std = errno;
        printf("strDst after: '%s',\t   strcpy returned: '%s'\n", buf, ret);
    }
    printf("ft_strcpy returned: %p\t strcpy returned: %p\t%s"
        "\terrno: %d\terrno_std: %d\t%s\n",
        ft_ret, ret, (ft_ret != ret) ? "❌" : "✅",
        errno_ret, errno_ret_std,
        (errno_ret != errno_ret_std) ? "❌" : "✅"
    );
}

static void ft_strcpy_test(void){
    printf("ft_strcpy test:\n");
    // ft_strcpy_test_one_string(NULL); // this will segfault in standard strcpy
    ft_strcpy_test_one_string("Hello World!");
    ft_strcpy_test_one_string("1");
    ft_strcpy_test_one_string("12");
    ft_strcpy_test_one_string("123");
    ft_strcpy_test_one_string("");
    ft_strcpy_test_one_string("\n");
}

static void ft_strdup_test_one_string(char *str){
    char buf[5000];
    char *ft_ret, *ret;
    int errno_ret = 0, errno_ret_std = 0;
    {
        memset(buf, 0, 5000);
        printf("strSrc: '%s',\t", str);
        ft_ret = ft_strdup(str);
        printf("ft_strdup returned: '%s'\n", ft_ret);
        if (ft_ret == NULL) {
            printf("ft_strdup returned NULL\n");
            return;
        }
        errno_ret = errno;
    }
    {
        memset(buf, 0, 5000);
        printf("strSrc: '%s',\t", str);
        ret = strdup(str);
        printf("strdup returned: '%s'\n", ret);
        if (ret == NULL) {
            printf("strdup returned NULL\n");
            free(ft_ret);
            return;
        }
        errno_ret_std = errno;
    }
    printf("ft_strdup returned: %p\t strdup returned: %p\t%s"
        "\terrno: %d\terrno_std: %d\t%s\n",
        ft_ret, ret, (strcmp(ft_ret, ret)) ? "❌" : "✅",
        errno_ret, errno_ret_std,
        (errno_ret != errno_ret_std) ? "❌" : "✅"
    );
}

static void ft_strdup_test(void){
    printf("ft_strdup test:\n");
    // ft_strdup_test_one_string(NULL); // this will segfault in standard strdup
    ft_strdup_test_one_string("Hello World!");
    ft_strdup_test_one_string("1");
    ft_strdup_test_one_string("12");
    ft_strdup_test_one_string("123");
    ft_strdup_test_one_string("");
    ft_strdup_test_one_string("\n");
}

int main(void)
{
    printf("\nTEST:ft_write\n=================\n");
    {
        int errno_ret = 0, errno_ret_std = 0;
        int ft_ret = ft_write(1, "Hello World!\n", 14);
        errno_ret = errno;
        int ret = write(1, "Hello World!\n", 14);
        errno_ret_std = errno;
        printf("ft_write return value: %d\n   write return value: %d\t%s"
            "\terrno: %d\terrno_std: %d\t%s\n",
            ft_ret, ret, (ft_ret != ret) ? "❌" : "✅",
            errno_ret, errno_ret_std,
            (ft_ret != ret) ? "❌" : "✅"
        );
    }
    {
        int errno_ret = 0, errno_ret_std = 0;
        int ft_ret = ft_write(-10, "Hello World with bad fd!\n", 28);
        errno_ret = errno;
        int ret = write(-10, "Hello World with bad fd!\n", 28);
        errno_ret_std = errno;
        printf("ft_write return value: %d\n   write return value: %d\t"
            "errno: %d\terrno_std: %d\t%s\n",
            ft_ret, ret, errno_ret, errno_ret_std,
            (ft_ret != ret) ? "❌" : "✅"
        );
    }

    printf("\nTEST:ft_read\n=================\n");
    char buf[5000];
    memset(buf, 0, 5000);
    printf("Put some text:\t");
    fflush(stdout);
    {
        int ft_ret = ft_read(0, buf, 5000);
        int ret = read(0, buf, 5000);
        printf("ft_read return value: %d\n, read return value: %d\t%s\n", ft_ret, ret, (ft_ret != ret) ? "❌" : "✅");
    }
    
    printf("\nTEST:ft_strlen\n=================\n");
    ft_strlen_test_one_string(buf);
    ft_strlen_test();

    printf("\nTEST:ft_strcmp\n=================\n");
    ft_strcmp_test();

    printf("\nTEST:ft_strcpy\n=================\n");
    ft_strcpy_test();

    printf("\nTEST:ft_strdup\n=================\n");
    ft_strdup_test();

	return 0;
}
