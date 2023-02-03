# DistanceCalculator

c++ distance calculator using openweather api because why not
# dependencies
you'll need nlohmann-json and curl libraries, if you're using any non-minimal linux distro you should be fine
# Build
Don't forget to put your api key as following : ``#define API_KEY = "{your_api_key}"`` inside ``main.cpp``

If the stupid idea of using this piece of trash software ever crosses your mind, you can build the project using the following commands :

``meson setup build`` \
``meson compile -C build``

the binary will then be inside the build/ folder,\ you just have to run it using ``./DistanceCalculator {city1} {city2}``

