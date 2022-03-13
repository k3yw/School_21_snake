
if test -z "$1"
then
    echo "Usage: sh create_class.sh 'Имя_Класса'"
    exit
fi

output_folder="../src/"

class_name=$1
class_namelowercase=$(echo $class_name | tr '[:upper:]' '[:lower:]')
class_nameuppercase=$(echo $class_name | tr '[:lower:]' '[:upper:]')

if [ -f "$output_folder$class_namelowercase.c" ]; then
    echo "$output_folder$class_namelowercase.c exists."
    exit
fi

if [ -f "$output_folder$class_namelowercase.h" ]; then
    echo "$output_folder$class_namelowercase.h exists."
    exit
fi

if [ -f "$output_folder$class_namelowercase.class.h" ]; then
    echo "$output_folder$class_namelowercase.class.h exists."
    exit
fi



test="$(cat TEMPLATE_H.FILE)"
test="$(echo "$test" | sed "s/\$class_name/$class_name/g")"
test="$(echo "$test" | sed "s/\$__class_nameuppercase/$class_nameuppercase/g")"
test="$(echo "$test" | sed "s/\$_class_namelowercase/$class_namelowercase/g")"
eval test

echo "$test" | dd of="$output_folder$class_namelowercase.h"



test="$(cat TEMPLATE_C.FILE)"
test="$(echo "$test" | sed "s/\$class_name/$class_name/g")"
test="$(echo "$test" | sed "s/\$__class_nameuppercase/$class_nameuppercase/g")"
test="$(echo "$test" | sed "s/\$_class_namelowercase/$class_namelowercase/g")"
eval test

echo "$test" | dd of="$output_folder$class_namelowercase.c"



test="$(cat TEMPLATE_CLASS.FILE)"
test="$(echo "$test" | sed "s/\$class_name/$class_name/g")"
test="$(echo "$test" | sed "s/\$__class_nameuppercase/$class_nameuppercase/g")"
test="$(echo "$test" | sed "s/\$_class_namelowercase/$class_namelowercase/g")"
eval test

echo "$test" | dd of="$output_folder$class_namelowercase.class.h"

echo "Successfully created class $1!"