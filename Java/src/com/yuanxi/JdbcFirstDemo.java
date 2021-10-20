package com.yuanxi;

import java.sql.*;

public class JdbcFirstDemo {
    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        //1.加载驱动
        Class.forName("com.mysql.cj.jdbc.Driver");
        //2.用户信息和url
        String url = "jdbc:mysql://localhost:3306/jdbcstudy?useUnicode=true&characterEncoding=utf8&useSSL=true";
        String username = "root";
        String password = "123456";
        //3.连接成功，数据库对象,connection代表数据库
        Connection connection = DriverManager.getConnection(url, username, password);
        //4.执行sql对象,statement执行sql对象
        Statement statement = connection.createStatement();
        //5.执行sql对象，去执行sql,可能存在结果，查看返回结果
        String sql = "select * from user";
        ResultSet resultSet = statement.executeQuery(sql);//返回的结果集

        while(resultSet.next()) {
            System.out.println("id="+resultSet.getObject("id"));
            System.out.println("name="+resultSet.getObject("name"));
            System.out.println("password="+resultSet.getObject("password"));
            System.out.println("email="+resultSet.getObject("email"));
            System.out.println("birthday="+resultSet.getObject("birthday"));
            System.out.println("===============================");
        }
        //6.释放连接
        resultSet.close();
        statement.close();
        connection.close();
    }
}
