// 关闭程序
function close_program(button, _console, input, input_status) {
    // 清空输出
    _console.empty();
    // 关闭窗口
    _console.closest(".console").addClass("p-0").css("min-height", "0");
    // 清空输入
    input.val("");
    // 清空程序执行状态
    input_status.empty();
    // 启用运行程序按钮
    button.removeClass("disabled").attr("onclick", button.data("onclick")).removeAttr("data-onclick");
}


// 结束 program 程序
function end_program(button, _console, printf, input, input_status, begin_time, return_value) {
    // 去掉程序执行时间小数有效位后的零
    let trim_back = function (a) {
        if (a[2] == '0') {
            a = a.substr(0, 2);
            if (a[1] == '0') {
                a = a.substr(0, 1);
                if (a[0] == '0') {
                    a = "";
                }
            }
        }
        return a;
    };
    // 生成三位随机数，作为程序执行时间小数最后三位
    let get_random_time = function () {
        let a = ("" + Math.random()).substr(2, 3);
        return trim_back(a);
    };
    // 输出程序执行时间
    printf("\n--------------------------------" +
        "\nProcess exited after " + ((new Date().getTime() - begin_time.getTime()) / 1000) + get_random_time() + " seconds with return value " + return_value +
        "\nPress any key to continue . . .");
    // 停止输入
    input.blur().off("input propertychange keydown");
    // 修改程序执行状态为【运行结束】
    input_status.find("span").first().html("<span>运行结束</span>");
    // 禁用运行程序按钮
    button.addClass("disabled").attr("data-onclick", button.attr("onclick")).removeAttr("onclick");
}


// 强制结束程序
function exit(controls, return_value) {
    end_program(...controls, return_value);
}


// 运行 program 程序
function operating_system(button, _console, input, input_status, begin_time, program) {
    // 定义标准输出函数
    let printf = function (str) {
        _console.append("<span>" + str + "</span>");
    };
    // 执行 program 程序
    let return_value = program(input, printf);
    // 结束 program 程序
    end_program(button, _console, printf, input, input_status, begin_time, return_value);
}


// 开始运行程序，按回车调用 operating_system(...) 函数
function start_program(button, console_id, program_console, program) {
    if (!program) {
        program = program_console;
        program_console = undefined;
    }
    // 用户按回车的次数
    let numOfEnter = 0, numOfInput = 0;
    // 获取运行程序按钮
    button = $(button);
    // 获取控制台容器
    let console_container = $("#" + console_id).find(".console");
    // 获取控制台
    let _console = console_container.find("pre");
    // 获取输入
    let input = $("#" + console_id + "-input");
    // 获取程序执行状态栏
    let input_status = $("#" + console_id + "-input-status");
    // 获取控制台容器的编号
    let console_num = console_id.substr(console_id.indexOf("-") + 1);
    // 记录程序运行开始时刻
    let begin_time = new Date();
    // 开启控制台
    console_container.removeClass("p-0").css("min-height", console_container.data("min-height"));
    if (program_console && _console) {
        // 运行控制台输出
        program_console(_console);
        // 统计输入数据的个数
        numOfInput = _console.find("[data-type='input']").length;
        // 修改程序执行状态为【正在输入】
        input_status.html("<span>正在输入</span>");
    } else {
        // 修改程序执行状态为【正在运行】
        input_status.html("<span>正在运行</span>");
    }
    // 添加关闭程序按钮
    $("<i class='fa fa-times-circle ml-2 text-danger' style='cursor:pointer;'></i>").on("click", function () {
        close_program(button, _console, input, input_status);
    }).appendTo(input_status);
    if (program_console) {
        // 获取所有的输入数据显示区域
        let span_input = _console.find("span[data-type='input']");
        // 特殊按键对应的显示符号
        let key_map = {
            9: "\t",
            13: "\n",
            32: " "
        };
        // 开始输入
        input.focus();
        // 将输入数据输出到控制台
        input.off("input propertychange").on("input propertychange", function () {
            if (span_input.length) {
                span_input.eq(numOfEnter).html(input.val().trim());
            }
        });
        // 当输入为回车时，运行 program 程序
        input.off('keydown').on('keydown', function (e) {
            if ([9, 13, 32].includes(e.keyCode)) {// 如果按下的键是 TAB, ENTER 或 SPACE
                ++numOfEnter;
                if (numOfEnter >= numOfInput) {
                    operating_system(button, _console, input, input_status, begin_time, program);
                } else {
                    span_input.get(numOfEnter - 1).after(key_map[e.keyCode]);
                    input.val("");
                }
            }
        });
    } else {
        setTimeout(function () {
            operating_system(button, _console, input, input_status, begin_time, program);
        }, 1);
    }
}

let run = start_program;

// 用递归模拟 C 语言的循环
function loop(button, console_id, program_console, program, controls) {
    if (!program) {
        program = program_console;
        program_console = undefined;
    }
    // 获取运行程序按钮
    button = $(button);
    // 获取控制台容器
    let console_container = $("#" + console_id).find(".console");
    // 获取控制台
    let _console = console_container.find("pre");
    // 获取所有的输入数据显示区域
    let span_input = _console.find("span[data-type='input']");
    // 用户已输入数据的个数，所有输入数据的个数
    let numOfEnter = span_input.length, numOfInput = span_input.length;
    // 获取输入
    let input = $("#" + console_id + "-input");
    // 获取程序执行状态栏
    let input_status = $("#" + console_id + "-input-status");
    // 获取控制台容器的编号
    let console_num = console_id.substr(console_id.indexOf("-") + 1);
    // 记录程序运行开始时刻
    let begin_time = new Date();
    // 开启控制台
    console_container.removeClass("p-0").css("min-height", console_container.data("min-height"));
    // 定义标准输出函数
    let printf = function (str) {
        _console.append("<span>" + str + "</span>");
    };
    // 存储控制台各控制部件
    if (!controls) {
        controls = [button, _console, printf, input, input_status, begin_time];
    }

    if (program_console && _console) {
        // 运行控制台输出
        program_console(_console);
        // 修改程序执行状态为【正在输入】
        input_status.html("<span>正在输入</span>");
    } else {
        // 修改程序执行状态为【正在运行】
        input_status.html("<span>正在运行</span>");
    }
    // 添加关闭程序按钮
    $("<i class='fa fa-times-circle ml-2 text-danger' style='cursor:pointer;'></i>").on("click", function () {
        close_program(button, _console, input, input_status);
    }).appendTo(input_status);
    if (program_console) {
        // 执行输出之后，还要更新输入区域的数量
        span_input = _console.find("span[data-type='input']");
        numOfInput = span_input.length;
        // 特殊按键对应的显示符号
        let key_map = {
            9: "\t",
            13: "\n",
            32: " "
        };
        // 开始输入
        input.focus().val("");
        // 将输入数据输出到控制台
        input.off("input propertychange").on("input propertychange", function () {
            if (span_input.length) {
                span_input.eq(numOfEnter).html(input.val().trim());
            }
        });
        // 当输入为回车时，运行 program 程序
        input.off('keydown').on('keydown', function (e) {
            if ([9, 13, 32].includes(e.keyCode)) {// 如果按下的键是 TAB, ENTER 或 SPACE
                ++numOfEnter;
                if (numOfEnter >= numOfInput) {
                    // 执行 program 程序
                    return program(controls, input, printf);
                } else {
                    span_input.get(numOfEnter - 1).after(key_map[e.keyCode]);
                    input.val("");
                }
            }
        });
    } else {
        setTimeout(function () {
            return program(controls, input, printf);
        }, 1);
    }
}
