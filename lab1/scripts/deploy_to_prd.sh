#!/bin/bash
# Переход на ветку prd
git checkout prd
# Слияние изменений из dev
git merge dev
# Установка тэга с текущей датой
git tag -a "deploy-$(date +%Y%m%d)" -m "Deploy from dev to prd"
# Пуш изменений и тэга
git push origin prd --tags
# Возврат на dev
git checkout dev

