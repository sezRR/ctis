$(function(){
    updateGrandTotal() ; // initially update grandTotal and selected product count
   $(".checkbox input").change(function(){
    updateGrandTotal();
   })
   $(".incBtn").click(function(){
       updatePrice($(this).parent().parent(), 1) ; 
   })
   $(".decBtn").click(function(){
       updatePrice($(this).parent().parent(), -1) ; 
    })
    function updatePrice(main, diff) {
      let cnt = Number(main.find(".amount").text()) ;
      cnt += diff;
      if (cnt <= 0) {
        main.remove() ;
      } else {
        let unitPrice = getUnitPrice(main) ;
        main.find(".amount").text(cnt) ;
        main.find(".price span").text(cnt * unitPrice) ;
      }
      updateGrandTotal() ;
    }
    function updateGrandTotal() {
        let grandTotal = 0 ;
        let selectedProductCount = $(":checked").each(function(){
            let price = $(this).parent().parent().find(".price span").text() ;
            grandTotal += Number(price) ;
        }).length ;
        $("header h1 span").text(grandTotal) ; // update total sum
        $("header h2 span").text(selectedProductCount) ; // length of checked checkboxes
    }
    function getUnitPrice(main) {
        let cnt =  main.find(".amount").text() ;
        let price = main.find(".price span").text() ;
        return price/cnt ;
    }
})