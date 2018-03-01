int getConfigInt(String message, String key) {
    String dataString = message; // abstract away from working directly with message
    char dataArray[size]; //declare char array for splitting into tokens
    dataString.toCharArray(dataArray, size);//convert string to array
    char* dataTok = strtok(dataArray, ",");// split into tokens and read each key-value pair
    while (dataTok != 0)
    {
      String configs(dataTok); //convert back to string to be analysed
      if (configs.substring(0, configs.indexOf(":")) == key)  //check if key = deviceid
      {
        String configString = configs.substring(configs.indexOf(":")); //find value in key-value pair
        configString.remove(0,1); //remove ":"
        int configInt = configString.toInt();
        return configInt;
      }
     // Find the next command in input string
     dataTok = strtok(0,",");
    }
}

String getConfigString(String message, String key) {
  //  String dataString = message; // abstract away from working directly with message
    char dataArray[size]; //declare char array for splitting into tokens
    message.toCharArray(dataArray, size);//convert string to array

    char* dataTok = strtok(dataArray, ",");// split into tokens and read each key-value pair
    while (dataTok != 0)
    {
      String configs(dataTok); //convert back to string to be analysed

      if (configs.substring(0, configs.indexOf(":")) == key)  //check if key = deviceid
      {
        String configString = configs.substring(configs.indexOf(":")); //find value in key-value pair
        configString.remove(0,1); //remove ":"
        return configString;
      }
     // Find the next command in input string
     dataTok = strtok(0, ",");
    }
}



String getConfigString(String message, String key) {
  if (message.substring(0,1) == "{") //identify message as json
  {
    String dataString = message; // abstract away from working directly with message
    char input[60]; //declare char array for splitting into tokens
    dataString.remove(dataString.indexOf("{"),1);//strip out bracket
    dataString.remove(dataString.indexOf("}"),1);//strip out bracket
    dataString.toCharArray(input, 60);//convert string to array

    char* configs = strtok(input, ",");// split into tokens and read each key-value pair
    while (configs != 0)
    {
      String another(configs); //convert back to string to be analysed

      if (another.substring(0, another.indexOf(":")) == key)  //check if key = deviceid
      {
        String potato = another.substring(another.indexOf(":")); //find value in key-value pair
        potato.remove(0,1); //remove ":"
        //Serial.println(potato); //do somethign with it
        return potato;
      }

     // Find the next command in input string
     configs = strtok(0, ",");
    }
  }
  else
  {
  return "not Json"; //not JSON
  }
}
