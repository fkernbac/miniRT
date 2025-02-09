# 42 miniRT Project
This project is a self-coded raytracer by [fkernbac](https://github.com/fkernbac) and [rbetz](https://github.com/Alphacharge).
It uses the [glfw Lib](https://github.com/glfw/glfw), [MLX42 V2.3.0](https://github.com/codam-coding-college/MLX42/commit/bf5dd7085b403974dd2d4e1e217877a518fc8915) and rbetz' [libft Lib](https://github.com/Alphacharge/mylibft/releases/tag/v1.0.0).

For the original school project with Norm compliance, refer to [v1.0.0](https://github.com/Alphacharge/miniRT/releases/tag/v1.0.0).

You need to install 'cmake' and 'glfw3' manually!
## Installation
This project should compile under Mac OS and Unix:
```
git clone https://github.com/Alphacharge/miniRT.git
cd miniRT
make
```

## Description
The raytracer supports the following objects:
- Cameras
- Ambient Lights
- Point Lights
- Planes
- Spheres
- Cylinders
- Cuboids

Additionally you can declare a **Resolution** in the scenefile.

This multithreaded raytracer handles hard shadows and introduces soft [shadows](https://www.peachpit.com/articles/article.aspx?p=486505&seqNum=6).

You can declare all objects multiple times, expect resolution.
## Usage
``./miniRT scenes/box.rt``

Keyhooks:
+ ESC	Exit programm
+ Space	switch to next camera
+ W		Move up
+ S		Move down
+ A		Move left
+ D		Move right
+ E		Zoom in
+ Q		Zoom out

> [!NOTE]
> Movement keys work based on the global coordinate system. Camera rotation doesn't matter!
## Pictures
