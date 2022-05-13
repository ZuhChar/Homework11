# 
# Makefile
# Author: Zachary Crimmel
# Date: May 13, 2022
#
# COSC 3750, Homework 11
#
# This is a Makefile designed to compile the mmute.c file
# Collaborated with Ian Moon on this Homework
#

CC=gcc
CFLAGS= -Wall -ggdb
RM= rm -f

.PHONY: all clean tidy

all: mmute

mmute: mmute.c
	${CC} ${CFLAGS} mmute.c -o mmute

clean:
	${RM} *.o mmute

tidy:
	${RM} a.out core.* mmute