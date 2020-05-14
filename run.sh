echo "compiling..."
gcc -o bin/main *.c
if [ $? == 0 ]
then
  echo "done.\n"
  ./bin/main
  rm ./bin/main
else
  echo "compilation error"
fi