#pragma once
#pragma warning(disable:4786)
//‘§±‡“Î
#include<iostream>
#include<fstream>
#define IN_WIN 1
#define IN_LINUX 2
#if 1
#define IN_WHERE IN_WIN
#elif 2
#define IN_WHERE IN_LINUX
#endif

#if IN_WHERE==IN_WIN
#include<windows.h>
#elif IN_WHERE==IN_LINUX
#include<curses.h>
#endif

#include<malloc.h>
#include<definition.h>
#include<Explanation.h>





