// 关闭控制台.
// 运行中关闭程序, Mode 为 Abort.
// 程序运行前初始化控制台, Mode 为 Start.
function close_program(button, _console, input, input_status, program_exit, Mode) {
    // 如果是程序运行中用户 kill 程序, 运行内存清理函数.
    if (Mode && Mode.includes("Abort")) {
        program_exit && program_exit();
    }
    // 清空输出
    _console.empty();
    // 关闭窗口
    _console.closest(".console").addClass("p-0");
    // 停止 & 清空输入
    input.blur().unbind().val("").addClass("hidden");
    // 清空程序执行状态
    input_status.empty();
    // Re-Enable 运行程序按钮
    reEnableButton(button, _console, input, input_status);
}


// 结束 program 程序, 清理内存, 在控制台输出程序运行时间和返回值.
function end_program(button, _console, printf, input, input_status, begin_time, program_exit, return_value) {
    // 运行程序结束清理内存函数.
    program_exit && program_exit();
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
    input.blur().unbind().val("").addClass("hidden");
    // 修改程序执行状态为【运行已结束】
    input_status.find("span").first().html("<span>运行已结束</span>");
    // 删除关闭程序 ✖️ 按钮
    input_status.find(".fa-times-circle").remove();
    // Re-Enable 运行程序按钮
    reEnableButton(button, _console, input, input_status);
    return return_value;
}

function reEnableButton (button, _console, input, input_status) {
    // Re-Enable 运行程序按钮
    const click = button.data("onclick");
    if (click) {
        button.unbind().on("click", function() {
            close_program(button, _console, input, input_status, undefined, "Start");
            setTimeout(() => {
                eval(click);
            }, 1);
        }).html("启动程序");
    } else {
        button.addClass("disabled");
        console.error("button has no data-onclick");
    }
    return 0;
}


// 强制结束程序, 清理内存, 在控制台输出程序运行时间和返回值.
function exit(controls, return_value) {
    return end_program(...controls, return_value);
}


// 运行 program 程序
function operating_system(button, _console, input, input_status, begin_time, program, program_exit) {
    // 定义标准输出函数
    const printf = function (str) {
        // Remove loading mark
        if (_console.find(".loading-mark").length) {
            _console.find(".loading-mark").remove();
        }
        _console.append("<span>" + str + "</span>");
    };
    // 执行 program 程序
    let return_value = program(input, printf);
    // 结束 program 程序
    end_program(button, _console, printf, input, input_status, begin_time, program_exit, return_value);
}


// 开始运行程序
// if Mode.includes("IsLoop") == true 按回车运行 program 程序.
// if Mode.includes("IsLoop") == false 按回车调用 operating_system 运行 program 程序.
// if Mode.includes("GetLine") == true 输入回车时停止输入, 运行程序.
// if Mode.includes("GetLine") == false 输入回车次数达到 numOfInput 时, 运行程序.
// Parameters: 1 button, 2 console_id, 3 program_console, 4 program, 5 controls, 6 Mode, 7 program_exit.
function start_program(button, console_id, program_console, program, controls, Mode, program_exit) {

    // 获取运行程序按钮
    button = $(button);
    if (button && button.length) {
        // 保存 onclick for Re-Enable
        if (button.attr("onclick")) {
            button.data("onclick", button.attr("onclick")).removeAttr("onclick");
        }
    } else {
        console.error("button not found.");
    }
    // 获取控制台容器
    const console_container = $("#" + console_id).find(".console");
    if (console_container && console_container.length) {
    } else {
        console.error("console_container not found.");
    }
    // 获取控制台
    const _console = console_container.find("pre");
    if (_console && _console.length) {
    } else {
        console.error("_console not found.");
    }
    // 获取输入
    const input = $("#" + console_id + "-input");
    // 获取程序执行状态栏
    const input_status = $("#" + console_id + "-input-status");

    // Disable 运行程序按钮
    button.unbind().on("click", function() {
        close_program(button, _console, input, input_status, program_exit, "Abort");
    }).html("停止程序");

    // 记录程序运行开始时刻
    const begin_time = new Date();

    // 定义标准输出函数(用于递归模拟循环)
    const printf = function (str) {
        _console.append("<span>" + str + "</span>");
    };
    // 存储控制台各控制部件(用于递归模拟循环)
    if (!controls) {
        controls = [button, _console, printf, input, input_status, begin_time, program_exit];
    }
    if (!Mode) {
        Mode = "";
    }

    // 开启控制台
    console_container.removeClass("p-0");
    // 清空程序执行状态
    input_status.empty();
    // 添加关闭程序按钮
    $("<i class='fa fa-times-circle ml-2 text-danger' style='cursor:pointer;'></i>").on("click", function () {
        close_program(button, _console, input, input_status, program_exit, "Abort");
    }).appendTo(input_status);

    if (program_console && _console) {
        // 运行控制台输出
        program_console(_console);
        // 修改程序执行状态为【正在输入】
        input_status.prepend("<span>正在输入</span>");
        // 获取所有的输入数据显示区域
        let span_input = _console.find("span[data-type='input']");
        // 统计输入数据的个数(运行控制台输出之后,才能开始统计输入区域的数量)
        let numOfInput = span_input.length;
        // 特殊按键对应的显示符号
        let key_map = {
            9: "<span>&nbsp;&nbsp;&nbsp;&nbsp;</span>",
            13: "<br>",
            32: "<span>&nbsp;</span>"
        };
        // Enable Input// 开始输入
        input.removeClass("hidden").val("").focus();
        // 用户按回车的次数
        // If this is not in a loop, num_of_enter begins with 0
        let numOfEnter = 0;
        // If this is in a loop, then go to the last input.
        if (Mode.includes("IsLoop")) {
            numOfEnter = numOfInput - 1;
        }

        // show the blinking cursor to indicate input
        span_input.eq(numOfEnter).addClass("has-blinking-cursor");

        // If user is typing spaces, then IsTypingSpaces is true.
        let IsTypingSpaces = false;
        // The spaces and enters user inputs will be put into spanSeparator
        let spanSeparator = undefined;


        if (Mode.includes("GetLine")) {
            // If Mode.includes("GetLine") == true
            // Get one line (including whitespaces) and then run the program.
            input.off("input propertychange").on("input propertychange", function () {
                    // sync the value of the hidden input with the value of the current input.
                    span_input.last().html(input.val());
            });
            // If Mode.includes("GetLine") == true, Only ENTER will terminate
            // the current input. Whitespaces is allowed in the inputs and will not
            // terminate the current input.
            input.off('keydown').on('keydown', function (e) {
                if ([13].includes(e.keyCode)) {
                    // If input is ENTER
                    // remove the blinking cursor for current input
                    $(".has-blinking-cursor").removeClass("has-blinking-cursor");
                    // Run the program
                    if (Mode.includes("IsLoop")) {
                        // 用递归模拟 C 语言的循环
                        return program(controls, input, printf);
                    } else {
                        operating_system(button, _console, input, input_status, begin_time, program, program_exit);
                    }
                }
            });
        } else {
            // 将输入数据输出到控制台
            input.off("input propertychange").on("input propertychange", function () {
                if (IsTypingSpaces == false && numOfInput > 0 && numOfEnter < numOfInput) {
                    // show a cursor on the console to indicate inputs.
                    span_input.eq(numOfEnter).html(input.val());
                }
            });
            // Listen to user input
            // If key is TAB or SPACE, then the current input stops,
            // and all TAB or SPACE user inputs will be put into spanSeparator,
            // numOfEnter will not change until user input a char which is not TAB, SPACE or ENTER.
            input.off('keydown').on('keydown', function (e) {
                let currentInput = span_input.eq(numOfEnter);
                if (IsTypingSpaces == false) {
                    // If user is typing non-space characters previously
                    if ([9, 32].includes(e.keyCode)) {
                        // 如果按下的键是 TAB 或 SPACE
                        // remove the blinking cursor for current input
                        $(".has-blinking-cursor").removeClass("has-blinking-cursor");
                        // Disable current input.
                        IsTypingSpaces = true;
                        // Create the separator and print spaces.
                        spanSeparator = $("<span data-type='input-spaces' class='has-blinking-cursor'></span>");
                        spanSeparator.append(key_map[e.keyCode]);
                        currentInput.after(spanSeparator);
                        // If user inputs TAB, should re-focus the input area.
                        if (e.keyCode == 9) {
                            setTimeout(() => {
                                input.focus();
                            }, 1);
                        }
                        // If current input is the last input, and user inputs space,
                        // should update numOfEnter, wait for an ENTER to terminate the
                        // input and run the program.
                        if (numOfEnter + 1 == numOfInput) {
                            ++numOfEnter;
                        }
                    } else if ([13].includes(e.keyCode)) {
                        // If input is ENTER
                        // If user is typing non-space characters previously and now user is typing ENTER,
                        // Then the current input is finished.
                        // If the current input is the last input then disable current input (remove cursor)
                        // and run the program.
                        if (numOfEnter + 1 < numOfInput) {
                            // If current input is not last input and user input ENTER,
                            // Then stop current input and print separator.
                            // remove the blinking cursor for current input
                            $(".has-blinking-cursor").removeClass("has-blinking-cursor");
                            // Disable current input.
                            IsTypingSpaces = true;
                            // Create the separator and print <br>.
                            let s = $(key_map[e.keyCode]);
                            currentInput.after(s);
                            let c = $("<span>").addClass("has-blinking-cursor");
                            $(s).after(c);
                            spanSeparator = $(c);
                        } else {
                            // If current input is the last input and user inputs ENTER,
                            // then current input is over, disable current input and run the program
                            // remove the blinking cursor for current input
                            $(".has-blinking-cursor").removeClass("has-blinking-cursor");
                            // Create the separator and print <br>.
                            // let s = $(key_map[e.keyCode]);
                            // currentInput.after(s);
                            if (Mode.includes("IsLoop")) {
                                // 用递归模拟 C 语言的循环
                                return program(controls, input, printf);
                            } else {
                                operating_system(button, _console, input, input_status, begin_time, program, program_exit);
                            }
                        }
                    } else {
                        // If user is typing non-space characters previously and now user is typing non-space characters,
                        // Do nothing.
                    }
                } else if (IsTypingSpaces == true) {
                    // If user is typing spaces previously
                    if ([9, 32].includes(e.keyCode)) {
                        // 如果按下的键是 TAB 或 SPACE
                        // Remove the blinking cursor for current separator.
                        $(".has-blinking-cursor").removeClass("has-blinking-cursor");
                        // Create the separator and print spaces.
                        let s = $("<span data-type='input-spaces' class='has-blinking-cursor'></span>");
                        s.append(key_map[e.keyCode]);
                        spanSeparator.after(s);
                        spanSeparator = $(s);
                        // If user inputs TAB, should re-focus the input area.
                        if (e.keyCode == 9) {
                            setTimeout(() => {
                                input.focus();
                            }, 1);
                        }
                    } else if ([13].includes(e.keyCode)) {
                        // If input is ENTER
                        if (numOfEnter < numOfInput) {
                            // If user is typing spaces previously
                            // If current input is not last input and user input ENTER,
                            // Since user is typing spaces previously, current input must have been stopped.
                            // current input's blinking cursor must have been removed.
                            // So there's no need to remove the blinking cursor for current input.
                            // and the separator must have been created.
                            // we should not remove the blinking cursor for current separator.
                            // Create the separator and print <br>.
                            $(".has-blinking-cursor").removeClass("has-blinking-cursor");
                            let s = $(key_map[e.keyCode]);
                            spanSeparator.after(s);
                            let c = $("<span>").addClass("has-blinking-cursor");
                            $(s).after(c);
                            spanSeparator = $(c);
                        } else {
                            // If current input is last input and user input ENTER,
                            // then input is over, run the program
                            // Since IsTypingSpaces is true, user is typing spaces previously,
                            // so the separator is created and it's active now.
                            // Since we should run the program now,
                            // we should remove the blinking cursor for the current separator.
                            $(".has-blinking-cursor").removeClass("has-blinking-cursor");
                            // Create the separator and print <br>.
                            // let s = $(key_map[e.keyCode]);
                            // spanSeparator.after(s);
                            // Run the program
                            if (Mode.includes("IsLoop")) {
                                // 用递归模拟 C 语言的循环
                                return program(controls, input, printf);
                            } else {
                                operating_system(button, _console, input, input_status, begin_time, program, program_exit);
                            }
                        }
                    } else {
                        // If user is typing spaces previously and now it's typing non-space characters.
                        if (numOfEnter + 1 < numOfInput) {
                            // Since user is typing spaces previously, the current input must be stopped,
                            // and if the current input is not the last input, there is next input, go to the next input.
                            // Disable the current separator.
                            IsTypingSpaces = false;
                            $(".has-blinking-cursor").removeClass("has-blinking-cursor");
                            // go to the next input.
                            ++numOfEnter;
                            span_input.eq(numOfEnter).addClass("has-blinking-cursor");
                            input.val("");
                        } else {
                            // If current input is last input and user is typing spaces previously
                            // and now user types in some non-space characters,
                            // these inputs will not be stored. Just put them in a new input.
                            // print the characters user just typed in into the new input.
                            // Create the input and print characters.
                            $(".has-blinking-cursor").removeClass("has-blinking-cursor");
                            let s = $("<span data-type='input' class='has-blinking-cursor leaked'></span>");
                            spanSeparator.after(s);
                            span_input.push(s[0]);
                            numOfInput = span_input.length;
                            IsTypingSpaces = false;
                            numOfEnter = numOfInput - 1;
                            input.val("");
                        }
                    }
                }
            });
        }
    } else {
        // 修改程序执行状态为【正在运行】
        input_status.prepend("<span>正在运行</span>");
        // Run the program
        if (Mode.includes("IsLoop")) {
            // 用递归模拟 C 语言的循环
            return program(controls, input, printf);
        } else {
            setTimeout(function () {
                operating_system(button, _console, input, input_status, begin_time, program, program_exit);
            }, 1);
        }
    }
}




// Run program after printing the loading mark.
function printLoadingMarkAndRun(button, console_id, program_console, program, controls, Mode, program_exit) {
    // Print loading mark
    const _console = $('#' + console_id + ' .console pre');
    const loadingMark = $("<div class='loading-mark text-center w-100 bg-secondary' style='height: 12rem;padding-top: 4rem;'></div>");
    loadingMark.append("<i class='fa fa-spinner fa-pulse fa-3x fa-fw' style='font-size: 4rem;'></i>");
    _console.append(loadingMark);
    setTimeout(() => {
        // Run the Program
        start_program(button, console_id, program_console, program, controls, Mode, program_exit);
    }, 100);
}


let run = start_program;



// Define a fprintf method to implement fprintf in C language.
// This method requires sprintf method.
// You can assign a specific console to it and make your printf method.
// Example:
//
// const printf = function () {
//     const stdout = $('#result-1 > .console > pre');
//     return fprintf(stdout, ...arguments);
// }
function fprintf() {
    const args = Array.from(arguments);
    const DomElement = args.shift();
    const OutputStr = sprintf(...args);
    if (DomElement && DomElement.length) {
        $(DomElement).append("<span>" + OutputStr + "</span>");
    }
}