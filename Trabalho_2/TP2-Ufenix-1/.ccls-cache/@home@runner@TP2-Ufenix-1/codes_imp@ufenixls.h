#ifndef UFENIXLS_H
#define UFENIXLS_H

#include <assert.h>
#include <dirent.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Sort(const struct dirent **a, const struct dirent **b);

int SortByType(const struct dirent **a, const struct dirent **b);

int FilterDot(const struct dirent *line);

void ufenix_ls(const char *dir, bool show_all, bool sort_by_type);

int mainUfenix_ls(int argc, char *argv[]);

#endif
