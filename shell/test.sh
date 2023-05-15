#!/bin/bash

a=10;
b=20;
echo `expr ${a} + ${b}`;
echo `expr $a - $b`;
echo `expr $b / $a`;
if [ ${a} == ${b} ]
then
	echo 'a=b'
fi
if [ ${a} != ${b} ]
then
	echo 'a!+b'
fi
