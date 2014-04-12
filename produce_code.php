<?php
$class_name=$argv[1];
$macro = "V8_".strtoupper($class_name)."_H";

echo "#ifndef  ".$macro."\n";
echo "#define  ".$macro."\n";
echo "\n";
echo "\n";
echo "\n";
echo "#include \"element.h\"\n";
echo "\n";
echo "\n";
echo "class ".$class_name.":public Element{\n";
echo "public:\n";
echo "   virtual v8::Handle<v8::ObjectTemplate> embed();\n";
echo "public:\n";
echo "\n";
echo "   virtual Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);\n";
echo "   virtual void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);\n";
echo "};\n";
echo "#endif\n";



?>
