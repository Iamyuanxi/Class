package com.SaleManage;

import javax.swing.table.DefaultTableModel;
import java.util.Vector;

public class SalesmanWindowTableModel extends DefaultTableModel {
    static Vector<String> columns = new Vector<>();
    static {
        columns.addElement("代号");
        columns.addElement("姓名");
        columns.addElement("性别");
        columns.addElement("出生年月");
        columns.addElement("电话号码");
        columns.addElement("居住地址");
        columns.addElement("入职事件");
    }

    private SalesmanWindowTableModel() {
        super(null,columns);
    }

    private static SalesmanWindowTableModel salesmanWindowTableModel = new SalesmanWindowTableModel();

    public static SalesmanWindowTableModel assembleModel(Vector<Vector<Object>> data) {
        salesmanWindowTableModel.setDataVector(data,columns);
        return salesmanWindowTableModel;
    }

    public static void updateModel(Vector<Vector<Object>> data) {
        salesmanWindowTableModel.setDataVector(data,columns);
    }

    public static Vector<String> getColumns() {
        return columns;
    }

    @Override
    public boolean isCellEditable(int row, int column) {
        return false;
    }
}
