root=$(pwd)
if [ ! -d 'build' ]; then
  mkdir build
  echo "Build directory created!"
else
  echo "Build directory found!"
fi
if [ ! -d 'output' ]; then
  mkdir output
  echo "Output directory created!"
else
  echo "Output directory found!"
fi
cd build || exit
cmake ..
cmake --build .
./vmm "$root/input/init-dp.txt" "$root/input/input-dp.txt" "$root/output/output-dp.txt"
