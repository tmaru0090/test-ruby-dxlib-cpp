# -*- encoding : utf-8 -*-
# main.rb

x= 0
y = 100
dx = DxLib.new
dx.set_use_charcode_format(65001)
dx.change_window_mode(1)
dx.dxlib_init
dx.set_draw_screen(-2)
img_path = "./res/よくわかなすし.png"
img = dx.load_graph(img_path)
if img == -1 then
    p "img file not found."
    return 
end
while dx.process_message != -1 
    if dx.check_hit_key(1) == 1 then
        break
    end
    dx.clear_draw_screen()
    dx.draw_string(x,y,"おはようございます！",dx.get_color(x%255,y%255,255))
    dx.draw_extend_graph(-x*0.5,-y*0.5,-x*0.5+300,-y*0.5+300,img,0)
    dx.screen_flip()
    x+=0.5
    y+=0.5
end
dx.dxlib_end

