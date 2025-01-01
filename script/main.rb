require "./script/init"
require "./script/dxlib_const_variables"




dx = DxLib.new
x= 0
y = 100

dx.message_box("初期化ダイアログ","正常に初期化が完了しましたー",0x00000040)
dx.set_use_charcode_format(65001)
dx.change_window_mode(TRUE)
dx.dxlib_init
dx.set_always_run_flag(TRUE)
dx.set_draw_screen(-2)
img_path = "./res/よくわかなすし.png"
img = dx.load_graph(img_path)
if img == -1 then
    dx.message_box("リソースエラー","画像ファイル: #{img_path}のロードに失敗しましたー。終了しますー。",0x00000010)
    return 
end
snd_path = "./res/pokemon-bw-end.wav"
snd = dx.load_music_mem(snd_path)
if snd == -1 then
    dx.message_box("リソースエラー","音声ファイル: #{snd_path}のロードに失敗しましたー。終了しますー。",0x00000010)
    return 
end
dx.play_music_mem(snd,1)


while dx.process_message != -1 
    if dx.check_hit_key(1) == TRUE then
        bt = dx.message_box("終了ダイアログ","終了しますかー?",0x00000004|0x00000040)
        break if bt != 7 && bt == 6
    end
    dx.clear_draw_screen()
    dx.draw_string(x,y,"おはようございます！",dx.get_color(x%255,y%255,255))
    dx.draw_extend_graph(-x*0.5,-y*0.5,-x*0.5+100,-y*0.5+100,img,0)
    dx.screen_flip()
    x+=0.5
    y+=0.5
end
dx.dxlib_end

dx.message_box("終了ダイアログ","正常に終了しましたー",0x00000040)

