string decode_letter(mNode *Root, string code, int index)
{
if (Root==NULL)
  return"";
 if (index==code.size())       //last direction in code
 {
  if(code[index]==".")
    return Root->left->key;
  if (code[index]=="_")
    return Root->right->key;
  else return Root->key;
 }
 else                          //still going through code  
 { 
 if(code[index]==".")
    return decode_letter(Root->left,code,index+1);
 if (code[index]=="_")
    return decode_letter(Root->right,code,index+1);
 } 
 return "";   //back up in case everything goes wrong
}


string decode_wrapper(mNode *Root, string code)
{
string letter=decode_letter(Root,code,0)
return letter;
}

decode(mNode *Root, string Code)
{
string word="";
string letterCode="";
for(int i=0; i<=Code.size(); i++)
{
if (Code[i]==" ")  //NOT AN EMPTY STRING this is a space specifically. That is what splits letters
  {
  word=word+decode_wrapper(Root, letterCode)   //finds the next letter from the letterCode created.
  letterCode="";
  }
else
  letterCode=letterCode+Code[i];  //adds character onto string to be decoded for a letter
}
