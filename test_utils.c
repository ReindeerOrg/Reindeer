#include "utils/utils.h"
#include <stdio.h>
void print_func(void* data){
    StringPrint((String)data);
}
int main() {
    String str1 = StringInit1("Hello");
    String str2 = StringInit2("World", 5);
    String str3 = StringInit3(str1);
    String str4 = IntToString(123);
    String str5 = DecimalToString(123.456);

    StringPrint(str1);
    printf("\n");
    StringPrint(str2);
    printf("\n");
    StringPrint(str3);
    printf("\n");
    StringPrint(str4);
    printf("\n");
    StringPrint(str5);
    printf("\n");
    
    StringConcat1(str1, str2);
    StringPrint(str1);
    printf("\n");

    StringConcat2(str1, '!');
    StringPrint(str1);
    printf("\n");

    String str6 = StringSlice(str1, 0, 5);
    printf("\n");

    StringPrint(str1);
    printf("\n");
    StringPrint(str2);
    printf("\n");
    StringPrint(str3);
    printf("\n");
    StringPrint(str4);
    printf("\n");
    StringPrint(str5);
    printf("\n");
    StringPrint(str6);
    printf("\n");

    printf("\n");

    List list = CreateList1();
    ListPushBack(list, str2);
    ListPushBack(list,str3);
    ListPushBack(list,str4);
    
    StringPrint((String)ListGet(list, 0));
    printf("\n");
    StringPrint((String)ListGet(list, 1));
    printf("\n");
    StringPrint((String)ListGet(list, 2));
    printf("\n");

    printf("\n");

    ListSet(list, 0, str5);
    ListSet(list, 1, str6);

    StringPrint((String)ListGet(list, 0));
    printf("\n");
    StringPrint((String)ListGet(list, 1));
    printf("\n");
    StringPrint((String)ListGet(list, 2));
    printf("\n");

    printf("\n");

    ListPrint(list, print_func);

    StringPrint((String)ListPop(list, 2));
    printf("\n");
    printf("\n");

    ListPrint(list, print_func);

    ListDestroy(list, NULL);
    StringDestroy(str1);
    StringDestroy(str2);
    StringDestroy(str3);
    StringDestroy(str4);
    StringDestroy(str5);
    StringDestroy(str6);
    return 0;
}
