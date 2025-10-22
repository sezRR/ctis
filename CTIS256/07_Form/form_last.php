<?php
extract($_POST) ;
$cities = ["Ankara", "İstanbul", "İzmir"] ;
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Web Form App</title>
</head>
<body>    
            <h1>Web Form App</h1>
            <form method="post">
                <table>
                    <tr>
                        <td>Name:</td>
                        <td><input type="text" name="username" value="<?php if(isset($username)) echo $username; ?>"></td>
                    </tr>
                    <tr>
                        <td>Password:</td>
                        <td><input type="password" name="pass" value="<?=isset($pass)?$pass:''?>"></td>
                    </tr>
                    <tr>
                        <td>Languages:</td>
                        <td>
                            <input type="checkbox" name="C" id="C" <?=isset($C)?'checked':''?>>
                            <label for="C">C</label>

                            <input type="checkbox" name="JS" id="JS" <?=isset($JS)?'checked':''?>>
                            <label for="JS">JS</label>

                            <input type="checkbox" name="Java" id="Java" <?=isset($Java)?'checked':''?>>
                            <label for="Java">Java</label>
                        </td>
                    </tr>
                    <tr>
                        <td>Fruits:</td>
                        <td>
                            <input type="checkbox" name="fruits[]" id="Cherry" value="Cherry"
                            <?=isset($fruits)&&in_array("Cherry", $fruits)?'checked':''?>
                            >
                            <label for="Cherry">Cherry</label>

                            <input type="checkbox" name="fruits[]" id="Banana" value="Banana"
                            <?=isset($fruits)&&in_array("Banana", $fruits)?'checked':''?>
                            >
                            <label for="Banana">Banana</label>

                            <input type="checkbox" name="fruits[]" id="Apple" value="Apple"
                            <?=isset($fruits)&&in_array("Apple", $fruits)?'checked':''?>
                            >
                            <label for="Apple">Apple</label>
                        </td>
                    </tr>
                    <tr>
                        <td>Status:</td>
                        <td>
                            <input type="radio" name="status" id="undergrad" value="undergrad" 
                            <?php
                                if(isset($status) && $status == "MSc")
                                    echo 'checked';
                            ?>
                            >
                            <label for="undergrad">Undergrad</label>

                            <input type="radio" name="status" id="MSc" value="MSc"
                            <?=isset($status)&&$status=="MSc"?'checked':''?>
                            >
                            <label for="MSc">MSc</label>

                            <input type="radio" name="status" id="PHD" value="PHD"
                            <?=isset($status)&&$status=="MSc"?'checked':''?>
                            >
                            <label for="PHD">PHD</label>
                        </td>
                    </tr>
                    <tr>
                        <td>Cities:</td>
                        <td>
                        <select name="city" id="city" >
                            <?php 
                            for($i=0; $i<count($cities); $i++){
                                echo "<option value=\"$i\"";
                                if(isset($city) && $city==$i)
                                    echo "selected ";
                                echo ">$cities[$i]</option>";   
                            }                                                             
                            ?>
                            </select>
                        </td>
                    </tr>
                    <tr>
                        <td>Message:</td>
                        <td>
                            <textarea name="message" cols="30" rows="5"><?=isset($message)?$message:''?></textarea>
                        </td>
                    </tr>
                    <tr>
                        <td colspan="2">
                            <input type="submit" value="Send" name="btnSend">
                        </td>
                    </tr>
                </table>

            </form>
     <?php
       if ( isset($btnSend)) {
        echo "<p>POST Request</p>" ;        
        
        echo "<p>Username is $username</p>" ;
        echo "<p>Password is $pass</p>" ;
        echo "<p>Fruits : " , isset($fruits) ? join(", ", $fruits) :  "None", "</p>" ;
        echo "<p>C Language : ", isset($C) ? "YES" : "NO", "</p>" ;
        echo "<p>JS : ", isset($JS) ? "YES" : "NO", "</p>" ;
        echo "<p>Java : ", isset($Java) ? "YES" : "NO", "</p>" ;
        echo "<p>Status : $status</p>" ;
        echo "<p>City : ", $cities[$city] , "</p>" ;
        echo "<p>Message : $message</p>" ;
        echo "<div><a href='form.php'>Go back to web form</a></div>" ;
   } 
     ?>
</body>
</html>