package com.SaleManage.util;

import java.sql.*;

public class DatabaseLink {
    private static final String URL = "jdbc:mysql://localhost:3306/salesmanage?useUnicode=true&characterEncoding=utf8&useSSL=true";
    private static final String DRIVER = "com.mysql.cj.jdbc.Driver";
    private static final String USER_NAME = "root";
    private static final String PWD = "123456";
    //加载驱动
    static {
        try {
            Class.forName(DRIVER);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
    //连接成功，数据库对象,connection代表数据库
    public static Connection getConn() {
        try {
            return DriverManager.getConnection(URL, USER_NAME, PWD);
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return null;
    }
    //释放连接
    public static void closeConn(Connection connection) {
        if (connection != null) {
            try {
                connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    public static void closePs(PreparedStatement ps) {
        if (ps != null) {
            try {
                ps.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    public static void closeRs(ResultSet rs) {
        if (rs != null) {
            try {
                rs.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}
