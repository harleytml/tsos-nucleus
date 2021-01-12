#!/usr/bin/env bash

shopt -s globstar
rename 's/\.tns$//' **
dos2unix **