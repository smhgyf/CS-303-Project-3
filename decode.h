string decode_letter(Node Parent, string Code, int index)
{
if (Parent==NULL)
  return"";
 if (index==code.size())       //last direction in code
 {
  if(code[index]==".")
    return Parent->left->value;
  if (code[index]=="-")
    return Parent->right->value;
  else return Parent->value;
 }
 else                          //still going through code  
 { 
 if(code[index]==".")
    return decode_letter(Parent->left,code,index+1);
 if (code[index]=="-")
    return decode_letter(Parent->right,code,index+1);
 } 
 return "";   //back up in case everything goes wrong
}


string decode_wrapper(Node Parent, string code)
{
string letter=decode(Parent,Code,0)
return letter;
}

decode(Node Parent, string Code)
{
string word="";
string letterCode="";
for(int i=0; i<=Code.size(); i++)
{
if (Code[i]==" ")  //NOT AN EMPTY STRING this is a space specifically. That is what splits letters
  {
  word=word+decode_wrapper(Parent, Code)   //finds the next letter from the letterCode created.
  letterCode="";
  }
else
  letterCode=letterCode+Code[i];  //adds character onto string to be decoded for a letter
}
