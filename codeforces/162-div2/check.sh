g++ -o temp "$1"
./temp < input.txt > output.txt
if cmp --silent -- "expected.txt" "output.txt"; then
  echo "\nAll Tests Passed!!!!"
else
    diff -y expected.txt output.txt
  echo "\nTest Failed!"
fi