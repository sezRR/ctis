$(function () {
    const numberOfChecked = $(":checked").length
    let prices = []
    $("header h2 span").text(numberOfChecked)

    let totalCost = 0;
    $(".price").each(function (i) {
        const price = parseInt($(this).find("span").text())
        totalCost += price
        prices.push(price)
    });
    $("header h1 span").text(totalCost)

    $(".amountPanel .incBtn").on("click", function () {
        const priceIndex = $(this).closest("article").find(".checkbox input").attr("id");

        const $amount = $(this).siblings().first()
        $amount.text(parseInt($amount.text()) + 1)
        $(this).closest("article").find(".title .price span").text(prices[priceIndex] * parseInt($amount.text()))

        const $sum = $("header h1 span")
        $sum.text(parseInt($sum.text()) + prices[priceIndex])
    })

    $(".amountPanel .decBtn").on("click", function () {
        const priceIndex = $(this).closest("article").find(".checkbox input").attr("id");

        const $amount = $(this).siblings().last()
        $amount.text(parseInt($amount.text()) - 1)
        $(this).closest("article").find(".title .price span").text(prices[priceIndex] * parseInt($amount.text()))

        const $sum = $("header h1 span")
        $sum.text(parseInt($sum.text()) - prices[priceIndex])

        if ($amount.text() === "0")
            $(this).closest("article").remove()
    })
});