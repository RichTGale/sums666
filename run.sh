#!/bin/bash

gcc -o sums666 mycutils.h mycutils.c sums666.c

./sums666 words.txt sums666.txt
