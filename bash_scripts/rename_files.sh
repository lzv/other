#! /bin/bash

#в текущем каталоге находятся подкаталоги, в которых находятся файлы картинок 
#формат имени файлов: "ненужная часть (номер).jpg", причем номер без ведущих нулей
#нужно убрать лишнюю часть, убрать скобки, и дополнить номер нулями до трех знаков 

find ./ -type f | while read F; do
	fdir=`dirname "$F"`
	fname=`basename "$F"`
	fname=`echo $fname | sed 's/(\([0-9]\))/(0\1)/'` #добавляем 0 к номерам из одной цифры
	fname=`echo $fname | sed 's/(\([0-9]\{2\}\))/(0\1)/'` #добавляем 0 к номерам из двух цифр, включая измененные на предыдущей строке
	fname=`echo $fname | sed 's/^.\+(\([0-9]\+\))/\1/'` #теперь везде только 3 цифры, убираем лишнее 
	mv "$F" "$fdir/$fname"
done
