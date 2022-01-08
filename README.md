# mini-debugger

a linux mini debugger written in c++.

# Run

## 前提

首先要安装 cmake 工具，通过以下命令：

```jsx
sudo apt install cmake
```

注：如果在 `make` 时出现 `No CMAKE_CXX_COMPILER could be found.`，执行如下命令即可。

```jsx
sudo apt-get update
sudo apt-get install -y build-essential
```

## 编译 & 运行

1. 拉取 submodule

```sh
cd ext

git submodule init
git submodule update

```

2. 执行 cmake

```sh
cmake .
```

3. 执行 make

```sh
make
```

4. 运行程序

```sh
./minidbg hello
```
