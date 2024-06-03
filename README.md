# cpp package managers

visiting cpp package managers agains

a few years after the ross/opencv build with conan failed to materialized
let's try the vcpkg to test local dev and then see how well it could work
for a build pipeline in github actions to produce native builds.
and is it a better option for toying around with cpp libraries than my
current solution of using nix shells?

so far:
local dev worked after a bit of fiddling
problems with producing cross compiling

issue:
there seems to be a linking issue with libdbus
it is linking to the vcpkg vendored version as opposed to the system one
this can be fixed with patchelf after compilation
but i still dont understand why its using its own shared object for libdbus
to link to

for now its viable enough?

This was tried after attending the rust course at HLUG and trying cargo
wanted to see if i could get better experience using more modern tools with cpp

## build

```bash
git clone https://github.com/microsoft/vcpkg
./vcpkg/bootstrap-vcpkg.sh -disableMetrics
./build.sh
```

[ ] - use CMakePresets.json to configure builds (remove build script after)
[ ] - add github workflow to produce builds for linux
