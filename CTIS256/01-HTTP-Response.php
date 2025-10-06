<?php
   // This is a php program that generates html output.
   // HTTP RESPONSE PACKET

   // 1. HTTP STATUS LINE
   // status line (Web server automatically place 200 or 404)
   http_response_code(200) ; // this line is redundant.
 
   // 2. RESPONSE HEADER 
   // html content is default content type. You don't have to write the following
   // line.
   // You can generate any content type from image to pdf documents.
   // However, you need to tell the browser the content type explicitly 
   header("Content-Type: text/html") ;
   // header("Content-Type: text/text") ;
   // header("Content-Type: image/jpg") ;
   // header("Content-Type: application/json") ;
   // header("Content-Type: application/pdf") ;
   
   
   // 3. RESPONSE BODY 
   // "echo" is a built-in statement (not a function) used to generate output to browser.
   // String or Text are prepared by double/single quotes.
   // This page builds an html page.
   echo "<!DOCTYPE html>\n";
   echo "<html>" ;
   echo "<head>" ;
   echo "<meta charset=\"UTF-8\">" ;
   echo "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">" ;
   echo "<title>HTTP Response</title>" ;
   echo "</head>" ;
   echo "<body>" ;
   echo "<h1>Introduction to PHP</h1>" ;
   echo "<p>Random Number : ", rand(0,100), "</p>" ;
   echo "</body>" ;
   echo "<html>" ;
   

