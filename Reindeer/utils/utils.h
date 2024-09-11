#pragma once
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

#define ASSERT(cond,message) assert(cond && message);/*Raise exception if cond is false*/
#define NULL_PTR_ASSERT(ptr) ASSERT(ptr != NULL, "Null pointer exception.Unexpected nullptr.");/*Raise exception if ptr is NULL*/
#define INVALID_INDEX_ASSERT(idx, length) ASSERT(idx < length, "Invalid index exception. Index out of range.");/*Raise exception if idx is out of range*/

typedef struct __String* String;
//char* str is copied
String StringInit1(const char* str);
String StringInit2(const char* str, size_t length);//Length is the number of characters in the string
String StringInit3(const String str);//Deep copy
//Converts the number to a string
String IntToString(int64_t num);
String DecimalToString(long double num);

//Append str2 to str1. Note that str1 is modified i.e str1 = str1 + str2
void StringConcat1(const String str1, const String str2);
void StringConcat2(const String str1, char str2);

//Returns str[start:end]
String StringSlice(const String str, size_t start, size_t end);//End idx is not included

bool StringEq(const String str1, const String str2);//Return true if the strings are equal
bool StringIsEmpty(const String str);//Return true if the string is empty

size_t StringLength(const String str);//Return the length of the string
const char* StringData(const String str);//Return the raw data of the string

char StringGet(const String str, size_t idx);//Return the character at idx
void StringSet(String str, size_t idx, char c);//Set the character at idx to c

void StringPrint(const String str);//Print the string

void StringDestroy(String str);//The String object is destroyed, and it is also freed.




typedef struct __List* List;

List CreateList1();//Create an empty list
List CreateList2(List list,void* (*copy)(void* data));//Deep copy and the data is copied using copy function. Use NULL if you don't want to copy the data.

void ListPushBack(List list,void* data);//Note the data is not copied.Append data to the end of the list

void* ListGet(const List list, size_t idx);//The data is not copied. Return the data at idx
void* ListSet(List list, size_t idx, void* data);//The data is not copied. We return the old data after setting the new data at idx

void* ListPop(List list, size_t idx);//Pop the element at idx and also return it

size_t ListLength(List list);//Return the length of the list
bool ListIsEmpty(List list);//Return true if the list is empty


void ListPrint(const List list, void (*print)(void* data));//Print the list. The print function is called on void* data.
                                                        //If print is NULL, then the ptr is printed.

void ListDestroy(List list, void (*destroy)(void* data));//The List object is destroyed, and it is also freed. The destroy function is called on void* data.
                                                        //If destroy is NULL, then the data is not freed.

