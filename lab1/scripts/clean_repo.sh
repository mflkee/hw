#!/bin/bash
# Удаляем отслеживаемые файлы и директории
git clean -fd
# Удаляем изменения в отслеживаемых файлах
git reset --hard HEAD

