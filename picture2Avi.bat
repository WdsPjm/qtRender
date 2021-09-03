@echo off
fffmpeg -r 1 -f image2 -s 1920x1080 -i D:/clionCode/QtOpengl/cmake-build-release/images/image%d.bmp -vcodec libx264 -crf 5  -pix_fmt yuv420p D:/clionCode/QtOpengl/cmake-build-release/test.mp4

