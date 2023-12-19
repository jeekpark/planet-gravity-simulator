#!/bin/bash

git clone https://github.com/jeekpark/planet-gravity-simulator.git

compiler=$(cc --version)
arch=$(uname -m)

if [[ $compiler == *"gcc"* ]] && [ "$arch" = "x86_64" ]; then
  sfml_bundle="SFML-2.6.1-linux-gcc-64-bit.tar.gz"
elif [[ $compiler == *"clang"* ]] && [ "$arch" = "x86_64" ]; then
  sfml_bundle="SFML-2.6.1-macOS-clang-64-bit.tar.gz"
elif [[ $compiler == *"clang"* ]] && [ "$arch" = "arm64" ]; then 
  sfml_bundle="SFML-2.6.1-macOS-clang-arm64.tar.gz"
fi

sfml_bundle_out=${sfml_bundle%.tar.gz}

tar -xzvf ./planet-gravity-simulator/lib/sfml/$sfml_bundle -C ./planet-gravity-simulator/lib/sfml
mv ./planet-gravity-simulator/lib/sfml/$sfml_bundle_out ./planet-gravity-simulator/lib/sfml/2.6.1
mv ./planet-gravity-simulator/lib/sfml/2.6.1/extlibs/FLAC.framework ./planet-gravity-simulator/lib/sfml/2.6.1/Frameworks/FLAC.framework
mv ./planet-gravity-simulator/lib/sfml/2.6.1/extlibs/freetype.framework ./planet-gravity-simulator/lib/sfml/2.6.1/Frameworks/freetype.framework
mv ./planet-gravity-simulator/lib/sfml/2.6.1/extlibs/ogg.framework ./planet-gravity-simulator/lib/sfml/2.6.1/Frameworks/ogg.framework
mv ./planet-gravity-simulator/lib/sfml/2.6.1/extlibs/vorbis.framework ./planet-gravity-simulator/lib/sfml/2.6.1/Frameworks/vorbis.framework
mv ./planet-gravity-simulator/lib/sfml/2.6.1/extlibs/vorbisenc.framework ./planet-gravity-simulator/lib/sfml/2.6.1/Frameworks/vorbisenc.framework
mv ./planet-gravity-simulator/lib/sfml/2.6.1/extlibs/vorbisfile.framework ./planet-gravity-simulator/lib/sfml/2.6.1/Frameworks/vorbisfile.framework



make -C planet-gravity-simulator clangd
make -C planet-gravity-simulator all


