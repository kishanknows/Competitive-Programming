RED="\033[38;5;160m"
GREEN="\033[38;5;106m"
BOLD="\033[1m"
g++ -o temp "$1"
./temp < input.txt > output.txt
if cmp --silent -- "expected.txt" "output.txt"; then
  echo "${BOLD}${GREEN}\xE2\x9C\x94 Accepted!"
else
    diff -y expected.txt output.txt
  echo "${BOLD}${RED}\xE2\x9D\x8C Wrong Answer!"
fi