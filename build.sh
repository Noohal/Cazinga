#!/bin/bash

set -xe

gcc -o czg main.c lexer.c file.c token.c container.c parser.c
