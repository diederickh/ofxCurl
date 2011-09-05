<?php
/**
 * What follows is a very very basic upload handler. This is just an example
 * how one can handle uploaded files. I created this tiny script to test the 
 * file upload of ofxCurlForm and handling of the response.
 *
 *
 * @author	Diederick Huijbers <diederick_AT_apollomedia.nl>
 * @date 	2011.07.20
 */
function l($s) {
	file_put_contents('log.txt', date('Y-m-d',time()) ."\t" .$s ."\n", FILE_APPEND);
}
function e($s) {
	echo $s ."<br>";
}

$upload_dir = dirname(__FILE__) .'/uploads/';
$upload_path = $upload_dir .$_FILES['photo']['name'];
if(move_uploaded_file($_FILES['photo']['tmp_name'], $upload_path)) {
    l("photo: ".  basename( $_FILES['photo']['name']));
} else{
	l('photo: cannot upload');
}
l('name: ' .$_POST['name']);
l('email: ' .$_POST['email']);
l('secret: ' .$_POST['secret']);
l('------------------');
echo 'name=' .$_POST['name'] ."\n";

