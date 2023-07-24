package com.jdbcDemo;
import java.sql.*;

public class ConnectionDemo{
	public static void main(String args[])throws Exception {
		
		String driver = "oracle.jdbc.driver.OracleDriver";
		String url="jdbc:oracle:thin:@localhost:1521:xe";
		String user="system";
		String pass="####";
		Class.forName(driver);
		Connection con = DriverManager.getConnection(url,user,pass);
		System.out.println("Connection Successfull");
	}
}
