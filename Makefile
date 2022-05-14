# 
# Makefile
# Author: Zachary Crimmel
# Date: May 13, 2022
#
# COSC 3750, Homework 11
#
# This is a Makefile designed to compile the mmult.c file
# Collaborated with Ian Moon on this Homework
#

CC=gcc
CFLAGS= -Wall -ggdb
RM= rm -f

.PHONY: all clean tidy

all: mmult

mmult: mmult.c
	${CC} ${CFLAGS} mmult.c -o mmult -pthread

clean:
	${RM} *.o mmult

tidy:
	${RM} a.out core.* mmult