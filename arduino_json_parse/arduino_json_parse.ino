String msg_woq = "{\"name\":\"kevin\",\"age\":\"27\",\"gender\":\"male\"}";
String msg_wq = "{name:kevin,age:27,gender:male}";
String d_name = "name";

String getConfigString(String message, String key) {
  if (message.substring(0,1) == "{") //identify message as json
  {
    while(message.indexOf("\"")>0)
    {
      message.remove(message.indexOf("\""),1);//strip out quotes
    }
    char dataArray[60]; //declare char array for splitting into tokens
    message.remove(message.indexOf("{"),1);//strip out bracket
    message.remove(message.indexOf("}"),1);//strip out bracket
    message.toCharArray(dataArray, 60);//convert string to array

    char* dataTok = strtok(dataArray, ",");// split into tokens and read each key-value pair
    while (dataTok != 0)
    {
      String configs(dataTok); //convert back to string to be analysed

      if (configs.substring(0, configs.indexOf(":")) == key)  //check if key = deviceid
      {
        String configValue = configs.substring(configs.indexOf(":")); //find value in key-value pair
        configValue.remove(0,1); //remove ":"
        return configValue;
      }
     // Find the next command in input string
     dataTok = strtok(0, ",");
    }
  }
  else
  {
  return "not Json"; //not JSON
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println(getConfigString(msg_wq,d_name));
  Serial.println(getConfigString(msg_woq,"age"));
}

void loop() {

}
