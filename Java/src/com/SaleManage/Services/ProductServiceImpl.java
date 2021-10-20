package com.SaleManage.Services;

import com.SaleManage.Entity.ProductInformation;
import com.SaleManage.Request;
import com.SaleManage.TableDTO;
import com.SaleManage.util.DatabaseLink;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Vector;

public class ProductServiceImpl implements ProductService {
    @Override
    public TableDTO retrieveProducts(Request request) {
        StringBuilder sql = new StringBuilder();

        sql.append("select * from productInformation");

        if (request.getSearchKey() != null && !"".equals(request.getSearchKey().trim())) {
            sql.append(" where name like '%").append(request.getSearchKey().trim()).append("%'");
        }

        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        TableDTO returnDTO = new TableDTO();

        try {
            conn = DatabaseLink.getConn();
            ps = conn.prepareStatement(sql.toString());
            rs = ps.executeQuery();
            //查询记录
            returnDTO.setData(fillData(rs));

            return returnDTO;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            DatabaseLink.closeRs(rs);
            DatabaseLink.closePs(ps);
            DatabaseLink.closeConn(conn);
        }

        return null;
    }

    @Override
    public boolean add(ProductInformation productInformation) {
        StringBuilder sql = new StringBuilder();

        sql.append("insert into salesmanage.productinformation (code, name, totalNum, unitPrice, producer, stockDate) ");
        sql.append(" values(?,?,?,?,?,?)");

        Connection conn = null;
        PreparedStatement ps = null;

        try {
            conn = DatabaseLink.getConn();
            ps = conn.prepareStatement(sql.toString());
            ps.setString(1,productInformation.getCode());
            ps.setString(2,productInformation.getName());
            ps.setInt(3,productInformation.getTotalNumber());
            ps.setDouble(4,productInformation.getUnitPrice());
            ps.setString(5,productInformation.getProducer());
            ps.setString(6,productInformation.getStockDate());
            return ps.executeUpdate() == 1;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            DatabaseLink.closePs(ps);
            DatabaseLink.closeConn(conn);
        }

        return false;
    }

    @Override
    public ProductInformation getByName(String selectedProductName) {
        StringBuilder sql = new StringBuilder("select * from salesmanage.productinformation where name=?");

        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;

        ProductInformation productInformation = new ProductInformation();

        try {
            conn = DatabaseLink.getConn();
            ps = conn.prepareStatement(sql.toString());
            ps.setString(1,selectedProductName);
            rs = ps.executeQuery();

            while (rs.next()) {
                String code = rs.getString("code");
                String name = rs.getString("name");
                int totalNum = rs.getInt("totalNum");
                double unitPrice = rs.getDouble("unitPrice");
                String producer = rs.getString("producer");
                String stockDate = rs.getString("stockDate");

                productInformation.setCode(code);
                productInformation.setName(name);
                productInformation.setTotalNumber(totalNum);
                productInformation.setUnitPrice(unitPrice);
                productInformation.setProducer(producer);
                productInformation.setStockDate(stockDate);
            }

            return productInformation;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            DatabaseLink.closeRs(rs);
            DatabaseLink.closePs(ps);
            DatabaseLink.closeConn(conn);
        }

        return null;
    }

    @Override
    public boolean update(ProductInformation productInformation) {
        StringBuilder sql = new StringBuilder();

        sql.append("update salesmanage.productinformation set code=?,totalNum=?,unitPrice=?,producer=?,stockDate=? ");
        sql.append(" where name=?");

        Connection conn = null;
        PreparedStatement ps = null;

        try {
            conn = DatabaseLink.getConn();
            ps = conn.prepareStatement(sql.toString());

            ps.setString(1,productInformation.getCode());
            ps.setInt(2,productInformation.getTotalNumber());
            ps.setDouble(3,productInformation.getUnitPrice());
            ps.setString(4,productInformation.getProducer());
            ps.setString(5,productInformation.getStockDate());
            ps.setString(6,productInformation.getName());

            return ps.executeUpdate() == 1;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            DatabaseLink.closePs(ps);
            DatabaseLink.closeConn(conn);
        }

        return false;
    }

    @Override
    public boolean delete(String[] names) {
        StringBuilder sql = new StringBuilder();

        sql.append("delete from salesmanage.productinformation where name in (");

        int length = names.length;

        for (int i=0; i<length; ++i) {
            if (i == (length-1)) {
                sql.append("? )");
            } else {
                sql.append("?, ");
            }
        }

        Connection conn = null;
        PreparedStatement ps = null;

        try {
            conn = DatabaseLink.getConn();
            ps = conn.prepareStatement(sql.toString());

            for (int i=0; i<length; i++) {
                ps.setString(i + 1, names[i]);
            }

            return ps.executeUpdate() == length;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            DatabaseLink.closePs(ps);
            DatabaseLink.closeConn(conn);
        }

        return false;
    }

    private Vector<Vector<Object>> fillData(ResultSet rs) throws SQLException {
        Vector<Vector<Object>> data = new Vector<>();

        while (rs.next()) {
            Vector<Object> record = new Vector<>();
            //处理查出的每条记录
            String code = rs.getString("code");
            String name = rs.getString("name");
            int totalNum = rs.getInt("totalNUm");
            double unitPrice = rs.getDouble("unitPrice");
            String producer = rs.getString("producer");
            String stockDate = rs.getString("stockDate");

            record.addElement(code);
            record.addElement(name);
            record.addElement(totalNum);
            record.addElement(unitPrice);
            record.addElement(producer);
            record.addElement(stockDate);

            data.addElement(record);
        }

        return data;
    }
}
