#include "utils.h"
#include <stdio.h>
#include <string.h>
#define CAP_SIZE 100
struct __String{
    char* data;
    size_t length;
    size_t capacity;
};

String StringInit1(const char* str){
    return StringInit2(str, strlen(str));
}
String StringInit2(const char* str, size_t length){
    String string = malloc(sizeof(struct __String));
    if(length != 0){
        NULL_PTR_ASSERT(str);
    }
    string->data = malloc(length + CAP_SIZE);
    string->length = length;
    string->capacity =length + CAP_SIZE;
    if(length != 0){
        memcpy(string->data, str, length);
    }
    return string;
}
String StringInit3(const String str){
    NULL_PTR_ASSERT(str);
    return StringInit2(str->data, str->length);
}

String IntToString(int64_t num){
    char buffer[100];
    sprintf(buffer, "%ld", num);
    return StringInit1(buffer);
}
String DecimalToString(long double num){
    char buffer[100];
    sprintf(buffer, "%Lf", num);
    return StringInit1(buffer);
}

void StringConcat1(const String str1, const String str2){
    NULL_PTR_ASSERT(str1);
    NULL_PTR_ASSERT(str2);
    if(str2->length == 0){
        return;
    }
    size_t str1_length = str1->length;
    str1->length += str2->length;
    if(str1->length > str1->capacity){
        str1->capacity = str1->length + CAP_SIZE;
        str1->data = realloc(str1->data, str1->capacity);
    }
    memcpy(str1->data + str1_length, str2->data, str2->length);
}
void StringConcat2(const String str1, char str2){
    NULL_PTR_ASSERT(str1);
    size_t str1_length = str1->length;
    str1->length += 1;
    if(str1->length > str1->capacity){
        str1->capacity = str1->length + CAP_SIZE;
        str1->data = realloc(str1->data, str1->capacity);
    }
    str1->data[str1_length] = str2;
}

String StringSlice(const String str, size_t start, size_t end){
    NULL_PTR_ASSERT(str);
    INVALID_INDEX_ASSERT(start, str->length);
    INVALID_INDEX_ASSERT(end, str->length + 1);
    if(start >= end){
        return StringInit2(NULL,0);
    }
    return StringInit2(str->data + start, end - start);
}

bool StringEq(const String str1, const String str2){
    NULL_PTR_ASSERT(str1);
    NULL_PTR_ASSERT(str2);
    if(str1 == str2){
        return true;
    }
    if(str1->length != str2->length){
        return false;
    }
    return memcmp(str1->data, str2->data, str1->length) == 0;
}
bool StringIsEmpty(const String str){
    NULL_PTR_ASSERT(str);
    return str->length == 0;
}

size_t StringLength(const String str){
    NULL_PTR_ASSERT(str);
    return str->length;
}

const char* StringData(const String str){
    NULL_PTR_ASSERT(str);
    return str->data;
}

char StringGet(const String str, size_t idx){
    NULL_PTR_ASSERT(str);
    INVALID_INDEX_ASSERT(idx, str->length);
    return str->data[idx];
}
void StringSet(String str, size_t idx, char c){
    NULL_PTR_ASSERT(str);
    INVALID_INDEX_ASSERT(idx, str->length);
    str->data[idx] = c;
}

void StringPrint(const String str){
    NULL_PTR_ASSERT(str);
    for(size_t i = 0; i < str->length; i++){
        putchar(str->data[i]);
    }
}

void StringDestroy(String str){
    if(str == NULL){
        return;
    }
    if(str->data != NULL){
        free(str->data);
    }
    free(str);
}