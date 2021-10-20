package com.SaleManage;

import com.SaleManage.Services.ProductService;
import com.SaleManage.Services.ProductServiceImpl;

import javax.swing.*;
import java.awt.*;

public class ProductManageWindow extends JFrame {
    JPanel northPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
    JButton addButton = new JButton("添加产品信息");
    JButton updateButton = new JButton("修改产品信息");
    JButton deleteButton = new JButton("删除产品信息");
    JTextField searchText = new JTextField(20);
    JButton searchButton = new JButton("查询");
    JButton addMarketButton = new JButton("添加销售信息");

    JPanel southPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT));
    JButton preButton = new JButton("上一页");
    JButton nextButton = new JButton("下一页");

    ProductWindowTable windowTable = new ProductWindowTable();
    ProductManageWindowHandler productManageWindowHandler;


    public ProductManageWindow() {
        super("产品管理");
        Container contentPane = getContentPane();
        productManageWindowHandler = new ProductManageWindowHandler(this);
        //放置北边组件
        layoutNorth(contentPane);
        //放置中间的jTable
        layoutCenter(contentPane);
        //放置南边组件
        layoutSouth(contentPane);

        setSize(1000,800);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setResizable(false);
        setVisible(true);
    }

    private void layoutCenter(Container contentPane) {
        TableDTO dto = getTableDTO();
        ProductWindowTableModel productWindowTableModel = ProductWindowTableModel.assembleModel(dto.getData());
        //把jTable和model关联
        windowTable.setModel(productWindowTableModel);
        windowTable.renderRule();

        JScrollPane jScrollPane = new JScrollPane(windowTable);

        contentPane.add(jScrollPane,BorderLayout.CENTER);
    }

    private void layoutSouth(Container contentPane) {
        southPanel.add(preButton);
        southPanel.add(nextButton);
        contentPane.add(southPanel, BorderLayout.SOUTH);
    }

    private void layoutNorth(Container contentPane) {
        //增加事件监听
        addButton.addActionListener(productManageWindowHandler);
        updateButton.addActionListener(productManageWindowHandler);
        deleteButton.addActionListener(productManageWindowHandler);
        searchButton.addActionListener(productManageWindowHandler);
        addMarketButton.addActionListener(productManageWindowHandler);
        northPanel.add(addButton);
        northPanel.add(updateButton);
        northPanel.add(deleteButton);
        northPanel.add(searchText);
        northPanel.add(searchButton);
        northPanel.add(addMarketButton);
        contentPane.add(northPanel, BorderLayout.NORTH);
    }

    private TableDTO getTableDTO() {
        ProductService productService = new ProductServiceImpl();
        Request request = new Request();

        request.setSearchKey(searchText.getText().trim());

        TableDTO tableDTO = productService.retrieveProducts(request);

        return tableDTO;
    }

    public void reloadTable() {
        TableDTO dto = getTableDTO();

        ProductWindowTableModel.updateModel(dto.getData());

        windowTable.renderRule();
    }

    public String[] getSelectedProductNames() {
        int[] selectedRows = windowTable.getSelectedRows();
        String[] names = new String[selectedRows.length];

        for (int i=0; i< selectedRows.length; ++i) {
            int rowIndex = selectedRows[i];
            Object nameObj = windowTable.getValueAt(rowIndex, 1);
            names[i] = nameObj.toString();
        }

        return names;
    }
    public static void main(String[] args) {
        ProductManageWindow m = new ProductManageWindow();
    }
}
