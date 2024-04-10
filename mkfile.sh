#!/bin/bash

if [ $# -le 1 ]; then
    echo "フォルダ名が指定されていません"
else
    contest_name=$1
    folder_name=$1$2

    if [ ! -d "${contest_name}" ]; then
        mkdir -p "${contest_name}"
    fi

    if [ ! -d "${contest_name}/${folder_name}" ]; then
        mkdir -p "${contest_name}/${folder_name}"
    fi

    args=("$@")
    for ((i=3; i<=$#; i++)); do
        file_name="${contest_name}/${folder_name}/${args[i]}.cpp"
        cp template.cpp "${file_name}"
        code "${file_name}"
    done
    fi
