
files=($(find -E . -type f -regex "^.*.c|$"))

if [ ${#files[@]} -eq 0 ]; then
    echo "Не найдено .c файлов для проверки :("
    exit
fi

echo "Проверяем файлы :"
cd ../
for item in ${files[*]}
do
    python3 materials/linters/cpplint.py --extensions=c src/$item
done
