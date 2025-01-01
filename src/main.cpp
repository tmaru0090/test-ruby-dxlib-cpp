#include <ruby.h>
#include <iostream>
#include <fstream>
#include <string>
#include <DxLib.h>
#include <windows.h>

namespace RubyGlueCode{
    std::wstring UTF8ToWString(const std::string& utf8Str) {
        int len = MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1,NULL, 0);
        std::wstring wstr(len, L'\0');
        MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, &wstr[0], len);
        wstr.pop_back(); // Null文字を削除
        return wstr;
    }
    extern "C"{
        static VALUE __RUBY_MessageBox(VALUE self,VALUE title,VALUE text,VALUE utype){
            std::string _title = StringValueCStr(title);
            std::string _text = StringValueCStr(text);
            std::wstring wtitle = UTF8ToWString(_title);
            std::wstring wtext = UTF8ToWString(_text);
            int res = MessageBoxW(NULL,wtext.c_str(),wtitle.c_str(),NUM2INT(utype));
            return INT2NUM(res);
        }    
        static VALUE __RUBY_DxLib_Init(VALUE self){
            int res = DxLib_Init();
            return INT2NUM(res);
        }   
 
        static VALUE __RUBY_DxLib_End(VALUE self){
            int res = DxLib_End();
            return INT2NUM(res);
        }   
         
        static VALUE __RUBY_ProcessMessage(VALUE self){
            int res = ProcessMessage();
            return INT2NUM(res);
        }   
 
        static VALUE __RUBY_ChangeWindowMode(VALUE self,VALUE mode){
            int res = ChangeWindowMode(NUM2INT(mode));
            return INT2NUM(res);
        }   
 
        static VALUE __RUBY_DrawString(VALUE self,VALUE x,VALUE y,VALUE string,VALUE color){
            int res = DrawString(NUM2INT(x),NUM2INT(y),StringValueCStr(string),NUM2INT(color));
            return INT2NUM(res);
        }   
 
        static VALUE __RUBY_GetColor(VALUE self,VALUE r,VALUE g,VALUE b){
            int res = GetColor(NUM2INT(r),NUM2INT(g),NUM2INT(b));
            return INT2NUM(res);
        }   
           
        static VALUE __RUBY_SetUseCharCodeFormat(VALUE self,VALUE format){
            int res = SetUseCharCodeFormat(NUM2INT(format));
            return INT2NUM(res);
        }   
         
        static VALUE __RUBY_SetDrawScreen(VALUE self,VALUE screen){
            int res = SetDrawScreen(NUM2INT(screen));
            return INT2NUM(res);
        }   

 
        static VALUE __RUBY_ClearDrawScreen(VALUE self){
            int res = ClearDrawScreen();
            return INT2NUM(res);
        }   
 
        static VALUE __RUBY_ScreenFlip(VALUE self){
            int res = ScreenFlip();
            return INT2NUM(res);
        }   
 
        static VALUE __RUBY_LoadGraph(VALUE self,VALUE filename){
            int res = LoadGraph(StringValueCStr(filename));
            return INT2NUM(res);
        }   
 
        static VALUE __RUBY_DrawGraph(VALUE self,VALUE x,VALUE y,VALUE handle,VALUE transFlag){
            int res = DrawGraph(NUM2INT(x),NUM2INT(y),NUM2INT(handle),NUM2INT(transFlag));
            return INT2NUM(res);
        }   
 
        static VALUE __RUBY_CheckHitKey(VALUE self,VALUE keyCode){
            int res = CheckHitKey(NUM2INT(keyCode));
            return INT2NUM(res);
        }   
 

 
        static VALUE __RUBY_DrawExtendGraph(VALUE self,VALUE x1,VALUE y1,VALUE x2,VALUE y2,VALUE handle,VALUE transFlag){
            int res = DrawExtendGraph(NUM2INT(x1),NUM2INT(y1),NUM2INT(x2),NUM2INT(y2),NUM2INT(handle),NUM2INT(transFlag));
            return INT2NUM(res);
        }   

        static VALUE __RUBY_LoadMusicMem(VALUE self,VALUE filename){
            int res = LoadMusicMem(StringValueCStr(filename));
            return INT2NUM(res);
        }

        static VALUE __RUBY_PlayMusicMem(VALUE self,VALUE handle,VALUE playType){
            int res = PlayMusicMem(NUM2INT(handle),NUM2INT(playType));
            return INT2NUM(res);
        }
        static VALUE __RUBY_SetAlwaysRunFlag(VALUE self,VALUE flag){
            int res = SetAlwaysRunFlag(NUM2INT(flag));
            return INT2NUM(res);
        }
    }
}

namespace RubyWrap{
    extern "C"{
        static void registDxLibClass(){
            VALUE dxlibClassObj = rb_define_class("DxLib",rb_cObject);
            rb_define_method(dxlibClassObj,"dxlib_init",RubyGlueCode::__RUBY_DxLib_Init,0);
            rb_define_method(dxlibClassObj,"dxlib_end",RubyGlueCode::__RUBY_DxLib_End,0);
            rb_define_method(dxlibClassObj,"process_message",RubyGlueCode::__RUBY_ProcessMessage,0);
            rb_define_method(dxlibClassObj,"change_window_mode",RubyGlueCode::__RUBY_ChangeWindowMode,1);
            rb_define_method(dxlibClassObj,"draw_string",RubyGlueCode::__RUBY_DrawString,4);
            rb_define_method(dxlibClassObj,"get_color",RubyGlueCode::__RUBY_GetColor,3);
    
            rb_define_method(dxlibClassObj,"set_use_charcode_format",RubyGlueCode::__RUBY_SetUseCharCodeFormat,1);
            rb_define_method(dxlibClassObj,"set_draw_screen",RubyGlueCode::__RUBY_SetDrawScreen,1);
            rb_define_method(dxlibClassObj,"clear_draw_screen",RubyGlueCode::__RUBY_ClearDrawScreen,0);
            rb_define_method(dxlibClassObj,"screen_flip",RubyGlueCode::__RUBY_ScreenFlip,0);

            rb_define_method(dxlibClassObj,"load_graph",RubyGlueCode::__RUBY_LoadGraph,1);
            rb_define_method(dxlibClassObj,"draw_graph",RubyGlueCode::__RUBY_DrawGraph,4);
            rb_define_method(dxlibClassObj,"draw_extend_graph",RubyGlueCode::__RUBY_DrawExtendGraph,6);
            rb_define_method(dxlibClassObj,"check_hit_key",RubyGlueCode::__RUBY_CheckHitKey,1);

            rb_define_method(dxlibClassObj,"load_music_mem",RubyGlueCode::__RUBY_LoadMusicMem,1);
            rb_define_method(dxlibClassObj,"play_music_mem",RubyGlueCode::__RUBY_PlayMusicMem,2);
            rb_define_method(dxlibClassObj,"set_always_run_flag",RubyGlueCode::__RUBY_SetAlwaysRunFlag,1);
            rb_define_method(dxlibClassObj,"message_box",RubyGlueCode::__RUBY_MessageBox,3);
       
        }
    }
}


class RubyInterpreter{
private:
    std::string filename;
public:
    RubyInterpreter(int argc, char **argv,const std::string& filename){
        ruby_sysinit(&argc, &argv);  // Rubyのシステム初期化(これないとセグメンテーション違反)
        ruby_init();
        ruby_set_argv(argc, argv);
        ruby_init_loadpath();
        RubyWrap::registDxLibClass();
        this->filename = filename;
    }
    ~RubyInterpreter(){
        ruby_finalize();
    }
    
    void execute(){
        const char* filenameCStr = filename.c_str();
        int errInfo;
        rb_load_protect(rb_str_new_cstr(filenameCStr), 0, &errInfo);
        if (errInfo) {
            // エラーが発生した場合、Rubyの例外メッセージを取得
            VALUE error = rb_errinfo();  // 最後のエラー情報を取得
            if (NIL_P(error)) {
                std::cerr << "Unknown error occurred while loading Ruby script." << std::endl;
            } else {
                // エラーメッセージを取得して表示
                VALUE message = rb_funcall(error, rb_intern("message"), 0);
                const char* messageStr = StringValueCStr(message);
                std::cerr << "Error Ruby script: " << messageStr << std::endl;
            }
        }
    }
};

int main(int argc, char **argv) {  
    std::string filename("./script/main.rb");
    RubyInterpreter ruby(argc,argv,filename);
    ruby.execute();
    return 0;
}
