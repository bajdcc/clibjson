# clibjson（C++ 简易JSON处理器）

借鉴[CMiniLang](https://github.com/bajdcc/CMiniLang)的部分代码，实现最简单的JSON序列化功能。

主要借鉴了CMiniLang的类型系统、词法分析、语法分析、AST、内存管理等代码。

事实证明CMiniLang的框架还是非常经典耐用的（花了两个小时就改成了）。

现在才搞明白CMiniLang的前身[CParser](https://github.com/bajdcc/CParser)为什么效率这么低下：它使用std::regex作为lexer，而std::regex竟然是带回溯的NFA！！
可恨！是置我自己的[DFA分析器](https://github.com/bajdcc/jMiniLang/tree/master/src/main/kotlin/com/bajdcc/util/lexer/automata)于不顾吗？早知道就自己写一个了（vlpp就有现成的，逃

因此本系列lexer完全手写（包括整型和浮点的识别），当然你可以参考rapidjson项目中的手写识别方式（大佬所作）。

本说明完善中。

## 功能

- [x] 词法分析
- [x] 语法分析
- [x] 内存管理
- [x] ast结点操作读取
- [x] ast结点操作写入
- [ ] 美化
- [x] 反序列化（字符串到ast）
- [x] 序列化（ast到字符串）
- [ ] 对象键值判重
- [ ] 处理速度（这辈子都不可能的）
- [ ] benchmark

## 使用

```cpp
    try {
        auto json = R"(
{
  "author": "bajdcc",
  "project": "clibjson",
  "description": "json helper",
  "language": "cpp",
  "link": "https://zhuanlan.zhihu.com/learncpp",
  "test": {
    "list_1": [1, 2, 3, 4, 5],
    "list_2": [[], [[]], [[], []]]
  }
}
)";
        clib::cparser p(json);
        auto root = p.parse();
        clib::cast::print(root, 0, std::cout);
    } catch (const std::exception& e) {
        printf("ERROR: %s\n", e.what());
    }
```

## 参考

1. [CMiniLang](https://github.com/bajdcc/CMiniLang)
2. [rapidjson](https://github.com/Tencent/rapidjson)