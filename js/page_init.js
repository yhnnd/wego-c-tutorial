// 如果绕过首页直接打开了某个页面，就重新进入首页加载该页面

// function check_illegal_visit() {
//     let v = window.location.href.split("/");
//     let filename = v[v.length - 1].split('#')[0];
//     if (filename != "index.html") {
//         window.location.href = "index.html#" + filename;
//     }
// }
// check_illegal_visit();

// 适配移动设备
if (isMobile()) {
    $(".mobile-hidden").remove();
} else {
    $(".mobile-show").remove();
}

// 高亮代码
prettyPrint();

// 加载评论
// $(".comment-area").each(function () {
//     $(this).removeAttr("class").load($(this).attr("id") + ".html");
// });