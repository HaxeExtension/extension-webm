mkdir ndll/Mac64 2> /dev/null
pushd project
haxelib run hxcpp Build.xml -Dmac -DHXCPP_M64
popd