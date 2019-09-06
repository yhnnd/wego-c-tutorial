function isMobile() {
    var Agents = ["Android", "iPhone", "SymbianOS", "Windows Phone", "iPod"];
    var flag = false;
    for (var v = 0; v < Agents.length; v++) {
        if (navigator.userAgent.indexOf(Agents[v]) > 0) {
            flag = true;
            break;
        }
    }
    return flag;
}

function isiPad() {
    if (navigator.userAgent.indexOf("iPad") > 0) return true;
    return false;
}