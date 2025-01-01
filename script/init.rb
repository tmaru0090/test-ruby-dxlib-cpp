$LOAD_PATH.clear
paths = [
  "E:/windows/dev-tools/Ruby33-x64/lib/ruby/site_ruby/3.3.0",
  "E:/windows/dev-tools/Ruby33-x64/lib/ruby/site_ruby/3.3.0/x64-ucrt",
  "E:/windows/dev-tools/Ruby33-x64/lib/ruby/site_ruby",
  "E:/windows/dev-tools/Ruby33-x64/lib/ruby/vendor_ruby/3.3.0",
  "E:/windows/dev-tools/Ruby33-x64/lib/ruby/vendor_ruby/3.3.0/x64-ucrt",
  "E:/windows/dev-tools/Ruby33-x64/lib/ruby/vendor_ruby",
  "E:/windows/dev-tools/Ruby33-x64/lib/ruby/3.3.0",
  "E:/windows/dev-tools/Ruby33-x64/lib/ruby/3.3.0/win32",
  "E:/windows/dev-tools/Ruby33-x64/lib/ruby/3.3.0/x64-mingw-ucrt",
  "./"
]

# 新しいパスを$LOAD_PATHに追加
paths.each do |path|
  $LOAD_PATH.push(path.to_s)
end

